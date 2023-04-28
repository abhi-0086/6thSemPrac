//program 10 - Bucket sort

#include<bits/stdc++.h>
using namespace std;

void bucketSort(float arr[], int n){
    // Create n empty buckets
    vector<float> b[n];
    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
    // Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
 
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    float arr[n];
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    bucketSort(arr, n);
    cout << "Array after bucket sort:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}


// Enter the number of elements in the array: 8
// Enter the elements of the array:
// 0.23 0.78 0.95 0.43 0.56 0.87 0.23 0.67
// Array after bucket sort:
// 0.23 0.23 0.43 0.56 0.67 0.78 0.87 0.95

