//program 4 - Quick Sort

#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        // Base case: the sub-array has zero or one elements
        return;
    }
    // Choose a pivot element from the sub-array
    int pivotIndex = left + (right - left) / 2;
    int pivot = arr[pivotIndex];
    
    // Partition the sub-array into two sub-arrays
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    // Recursively apply quickSort to the sub-arrays
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main() {
    // Example usage of the quickSort function
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    cout << "\nBefore Sorting -> ";
    for(int i=0; i<6; i++)
        cout << arr[i] << " ";
    cout << endl;
    quickSort(arr, 0, arr.size() - 1);
    cout << "\nAfter Sorting -> ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}