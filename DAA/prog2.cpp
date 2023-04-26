//program 2 - Binary Search 

#include<bits/stdc++.h>
using namespace std;

void input_array(vector<int> &v, int size)
{
    for(int i=0; i<size; i++)
        cin >> v[i];
}

int binary_search(vector<int> v, int key)
{
    int lo = 0;
    int hi = v.size()-1;
    while(lo <= hi)
    {
        int mid = lo + (hi - lo)/2;
        if(v[mid] == key) //element found
            return mid;
        if(v[mid] > key)//discard right of mid, move to left part of array
            hi = mid - 1;
        else
            lo = mid + 1; 
    }
    return -1;//if element not found return -1
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements (in sorted order) : ";
    input_array(arr, n);
    int target;
    cout << "Enter the element you want to search : ";
    cin >> target;
    int ans = binary_search(arr, target);
    if(ans == -1)
        cout << target << " is not present in the array." << endl;
    else
        cout << target << " is present in array at index " << ans << endl;
    
    return 0;
}