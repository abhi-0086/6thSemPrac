//program 8 - Counting sort

#include <iostream>
using namespace std;
#include <algorithm>

void counting_sort(int arr[], int n) {
  // Find the range of the input array
  int max_val = *max_element(arr, arr + n);
  int min_val = *min_element(arr, arr + n);
  int range = max_val - min_val + 1;

  // Create a count array to store the frequency of each element
  int count[range] = {0};
  for (int i = 0; i < n; ++i) {
    ++count[arr[i] - min_val];
  }
  // Modify the count array to store the positions of each element
  for (int i = 1; i < range; ++i) {
    count[i] += count[i - 1];
  }
  // Create a new array to store the sorted output
  int sorted_arr[n];
  for (int i = n - 1; i >= 0; --i) {
    sorted_arr[count[arr[i] - min_val] - 1] = arr[i];
    --count[arr[i] - min_val];
  }

  // Copy the sorted array back to the original array
  copy(sorted_arr, sorted_arr + n, arr);
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements:\n";
  for (int i = 0; i < n; ++i) 
    cin >> arr[i];

  counting_sort(arr, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";

  return 0;
}
