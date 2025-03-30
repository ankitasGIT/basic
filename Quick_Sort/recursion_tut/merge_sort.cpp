#include<iostream>
using namespace std;

void mergeTwoArr(int arr[], int s, int mid, int e)
{
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* f = new int[len1];
    int* s = new int[len2];
    int i = 0;
    for(int j = s; j <= mid; j++)
    {
        f[i] = arr[j];
        i++;
    }

    int k = 0;
    for(int j = mid+1; j <= e; j++)
    {
        s[k] = arr[j];
        k++;
    }

    int org = 0;
    int i1 = 0, i2 = 0;

    while(i1 < len1 && i2 < len2)
    {
        if(f[i1] < s[i2])
        {
            arr[org] = f[i1];
            i1++;
            org++;
        }
        else
        {
            arr[org] = s[i2];
            i2++;
            org++;
        }
    }

    while(i1 < len1)
    {
        arr[org] = f[i1];
        org++;i1++;
    }
    while(i2 < len2)
    {
        arr[org] = s[i2];
        org++;i2++;
    }
}

void mergeSort(int arr[], int s, int e)
{
    if(s == e)
        return;

    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    mergeTwoArr(arr);
}

int main()
{
    return 0;
}