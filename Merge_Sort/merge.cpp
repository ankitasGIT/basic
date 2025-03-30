#include<bits/stdc++.h>
using namespace std;

void mergeTwoSortedArrays(int* arr, int s, int e)
{
    // cout << s << ", " << e << "\n" ;
    // cout << "Before sorting : \n";
    // for(int i = 0; i < 8; i++)
    // {
    //     cout << arr[i] << ", ";
    // }
    // cout << endl;

    //Find mid
    int mid = (s+e)/2;

    //Length of LHS array
    int len1 = mid - s + 1;
    //Length of RHS array
    int len2 = e-mid;

    //Create 2 arrays
    int* left = new int[len1];
    int* right = new int[len2];

    //Copy values 
    int k = s;
    for(int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }


    k = mid+1;
    for(int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    //Logic of merge 2 sorted arrays

    int l = 0, r = 0, i = s;
    while(l < len1 && r < len2)
    {
        if(left[l] <= right[r])
        {
            arr[i++] = left[l++];
        }
        else{
            arr[i++] = right[r++];
        }
    }

    while(l < len1)
    {
        arr[i++] = left[l++];
    }

    while(r < len2)
    {
        arr[i++] = right[r++];
    }
    // cout << "After sorting : \n";
    // for(int i = 0; i < 8; i++)
    // {
    //     cout << arr[i] << ", ";
    // }
    // cout << endl << endl;

}

void mergeSort(int* arr, int s, int e)
{
    if(s >= e)
    {
        return;
    }

    int mid = (s + e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
   
    mergeTwoSortedArrays(arr, s, e);
}


/*
    Complexity : 

ALL -> 

TC : O(N* log N)
SC : O(N)
 */

int main() 
{
    int arr[] = {4, 3, 15, 8, 6, 99, 36, 8};
    int n = 8;
    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }

}
