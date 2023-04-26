//program 3 - Bubble Sort

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &v)
{
    int size = v.size();
    // Loop through all array elements except last -> because the last element will always be in its correct position after each iteration of the inner loop.
    for(int i=0; i<size-1; i++)
    {
        bool swapped = false; // to optimize if no swap was there in any one iteration of inner loop then already sorted 
        for(int j=0; j<size-i-1; j++)
        {
            if(v[j] > v[j+1])
            {
                swapped = true;
                swap(v[j], v[j+1]);
            }
        }
        if(swapped == false)
            break;
    }
}

int main()
{
    vector<int> arr;
    int n;
    cout << "Enter the no of elements : ";
    cin >> n;
    cout << "Enter array elements : ";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout << "\nArray before sorting - > ";
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    //calling bubble sort function
    bubble_sort(arr);
    cout << "\n\nArray after sorting -> ";
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}