#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 1 2 3 4 5

void selection_sort(vector<int>& array)
{
    int i, j;
    for( i = 0; i < array.size()-1; i++)
    {
        //assume first as minimum
        int mini = i;
        //ajun chota index find karycha
        for( j = i+1; j < array.size(); j++)
        {
            if(array[j] < array[mini])
            {
                mini = j;
            }
        }
        //swap karycha mini sobat
        swap(array[i], array[mini]);
    }
}

/*
    TC -> O(N*N)
    SC -> O(1)

    All best, avg, worst
*/

void bubble_sort(vector<int>& arr)
{
    int i, j;
    //Go through array as many times until not sorted
    for(i = 0; i < arr.size(); i++)
    {
        //Sorting every iteration
        for(j = 0; j < arr.size(); j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

/*
    BEST ->

    TC : O(N) already sorted
    We can put a check if a value is not at all swappper for some iteration,
    than to stop

    AVG, WORST ->

    TC : O(N*N)

*/


void insertion_sort(vector<int>& arr)
{
    int i;
    for(i = 1; i < arr.size(); i++)
    {
        //Start from first
        int key = arr[i];
        //Run a loop backwords to sort
        for(int j = i-1; j >= 0; j--)
        {
            if(key < arr[j])
            {
                swap(arr[j+1], arr[j]);
            }
        }
    }
}

/*
    BEST : 
    TC -> O(N)

    AVG, WORST : O(N*N)
*/

int main()
{
    vector<int> v = {14, 33, 27, 10, 35};
    // insertion_sort(v);
    // selection_sort(v);
    bubble_sort(v);
    for(auto i: v)
        cout << i << "  ";
}