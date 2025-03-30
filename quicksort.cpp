#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    //choose pivot element & index
    int pivotInd = s;
    int pivotEl = arr[s];

    //send pivotEl to its correct position

    //logic?! --> pivotEl peksha chote kiti ahet tyacha count + s kela tr correct position yenar
    int count = 0;
    for(int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivotEl)
        {
            count++;
        }
    }

    int correctInd = s + count;
    //send pivotEl to correct position
    swap(arr[pivotInd], arr[correctInd]);

    //place pivotInd to correct position
    pivotInd = correctInd;

    //Left -> Smaller than pivot & Right -> Bigger than pivot
    int i = s, j = e;
    while(i < pivotInd && j > pivotInd)
    {
        //Fkt indexes store karun swap karyche 
        while(arr[i] <= pivotEl)
        {
            i++;
        }

        while(arr[j] > pivotEl)
        {
            j--;
        }

        //imp****
        //Swap karyche after checking konte elements violate kartat
        if(i < pivotInd && j > pivotInd)
            swap(arr[i++], arr[j--]);
    }


    //pivotInd return karycha
    return pivotInd;
}

void quickSort(int arr[], int s, int e)
{
    if(s >= e)
    {
        return;
    }

    //partition logic -> 1 case handled
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

/*
    Complexity : 

BEST, AVG -> 

TC : O(N * log N) 
SC : O(log N) balanced partition (recursive stack) 

WORST ->

TC : O(N*N) Pivot element is mean
SC : O(N) unbalanced partition

[5, 3, 9, 7, 10, 8]
*/


int main()
{
    int arr[] = {8, 1, 3, 4, 20, 50, 30};
    // int arr[] = {14, 33, 27, 10, 35, 8, 100};

    int n = 7, s = 0, e = n-1;
    quickSort(arr, s, e);

    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}