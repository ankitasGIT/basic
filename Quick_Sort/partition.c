#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 15
void show_arr(int *a, int N, const char*msg);
int partition(int *a, int p, int r);

int main(void)
{
    int a[15] = {30, 1, 44,
                75, 11, 2, 85, 17, 20, 25,
                100, 543, 123, 500};

    int q,p = 3,r = 10; 
    show_arr(a,ARRAY_SIZE, "Before partition():");
    q = parition(a,p,r);
    show_arr(a,ARRAY_SIZE, "After partition():");
    printf("q = %d\n", q);


    return(0);
}

void show_arr(int *a,int N, const char* msg)
{
    int k;
    if(msg)
        puts(msg);

    for(k = 0; k < N;k++)
    {
        printf("a[%d]:%d\n", k, a[k]);
    }
}

int partition(int *a, int p, int r)
{
    int i,j,pivot,tmp;

    pivot = a[r];
    i = p - 1;

    for(j = p; j < r; j++)
    {
        if(a[j] <= pivot)
        {
            i++;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[r];
    a[r] = a[i+1];
    a[i+1] = tmp;

    return(i+1);
}