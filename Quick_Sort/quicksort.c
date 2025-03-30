#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int partition(int* A, int p, int r)
{
    int i,j,tmp,pivot;

    i = p-1;
    pivot = A[r];
    for(j = p; j < r; j++)
    {
        if(A[j] <= pivot)
        {
            i++;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[r];
    A[r] = A[i+1];
    A[i+1] = tmp;

    return i+1;
}

void quick_sort(int* A,int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(A,p,r);
        quick_sort(A,p,q);
        quick_sort(A,q+1,r);
    }
}

int main(void)
{
    int a[10] = {values};

    show_arr(a, SIZE, "Before sorting():");
    quick_sort(a,0,9);
    show_arr(a, SIZE, "After sorting():");

    return(0);
}