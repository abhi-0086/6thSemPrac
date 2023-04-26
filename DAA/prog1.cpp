//program 1 - Linear Search

#include<bits/stdc++.h>
using namespace std;

void input_array(vector<int> &v, int size)
{
    for(int i=0; i<size; i++)
        cin >> v[i];
}

int linear_search(vector<int> v, int key)
{
    //linearly traverse each element of array and check if it is equal to search value if yes return the particular index
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] == key)
            return i;
    }
    //after complete traversal, means search value not present return -1
    return -1;
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements : ";
    input_array(arr, n);
    int target;
    cout << "Enter the element you want to search : ";
    cin >> target;
    int ans = linear_search(arr, target);
    if(ans == -1)
        cout << target << " is not present in the array." << endl;
    else
        cout << target << " is present in array at index " << ans << endl;
    
    return 0;
}