#include <iostream>
using namespace std;

/*

Formulae-

Parent = i/2
Left Child = 2*i
Right Child = 2*i + 1
Leaf Node index range = [(n/2 + 1), n]


TC - O(N * log N)

Flow -

1. Insert(val) :

TC - O(log N)
2. Sort() -> Heapify()


3. Deletion(): Means we want to delete root node

TC - O(log N)

*/

class heap
{
    int *arr;
    int size;

public:
    heap(int x = 15)
    {
        size = -1;
        arr = new int[x];
    }

    void insert(int x)
    {
        //Inc size
        size++;
        //Place x at size
        arr[size] = x;

        //Correct position pe leke jao -> ? 
        // Parent ko compare karo agar big/small he (wrong) swap

        int i = size;
        while (i > 0 && arr[i] > arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            //Continue checking for every parent
            i = (i - 1) / 2;
        }
    }

    void display()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " , ";
        }
        cout << endl;
    }

    void heapify(int i, int size)
    {
        //i = Node

        int l = 2 * i + 1;   //Left
        int r = 2 * i + 2;   //Right
        int large = i;       //Store index


        if (l <= size && arr[large] < arr[l])
            large = l;

        if (r <= size && arr[large] < arr[r])
            large = r;

        if (large != i)
        {
            swap(arr[large], arr[i]);
            heapify(large, size);
        }
    }

    void sort()
    {
        int i = size;

        while (i != 0)
        {
            swap(arr[0], arr[i]);

            i--;
            // 0 is first element 
            // i is size
            heapify(0, i);
        }
    }

    void del()
    {
        //Step 1 -> Delete root 
        //Swap last node with root/first    
        swap(arr[0], arr[size]);
        //Dec size
        size--;
        //Step 1 done

        //Step 2
        //Take root node to correct position

        //Logic ? 
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(i, this->size);
        }
    }
};

int main()
{

    cout << "HEllo\n";
    heap h1(20);

    h1.insert(21);
    h1.insert(216);
    h1.insert(6);
    h1.insert(11);
    h1.insert(25);
    h1.insert(67);
    h1.insert(100);

    h1.display();

    h1.del();
    h1.display();
    h1.sort();
    h1.display();
}