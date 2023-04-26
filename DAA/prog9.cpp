//program 9 - Radix sort

#include <iostream>
using namespace std;

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform the counting sort algorithm
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Counting the frequency of digits
    for (int i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++;

    // Updating the count array to contain the actual position of digits
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1];

    // Building the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // Copying the output array to the original array
    for (int i = 0; i < n; i++) 
        arr[i] = output[i];
}

// Function to perform radix sort on an array
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);
    // Performing counting sort for each digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Main function to take input and call the radix sort function
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);
    // Printing the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
