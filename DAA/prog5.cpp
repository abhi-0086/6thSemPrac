//program 5 - Merge Sort

#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // Size of left subarray
    int n2 = r - m;     // Size of right subarray
    // Create temporary arrays for left and right subarrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0;  // Index of left subarray
    int j = 0;  // Index of right subarray
    int k = l;  // Index of merged array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy any remaining elements of the left subarray
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy any remaining elements of the right subarray
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Function to perform merge sort on an array
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate the middle index

        // Recursively sort the left and right subarrays
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the two sorted subarrays
        merge(arr, l, m, r);
    }
}

// Main function to test the mergeSort function
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    // Call mergeSort function to sort the array
    mergeSort(arr, 0, n - 1);
    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
