#include <iostream>

using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void insert(int val) // O(log n)
    {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void del() // O(log n)
    {
        if (size == 0)
        {
            cout << "Underflow";
            return;
        }

        // step1: put last element to first index
        arr[1] = arr[size];
        size--;

        int i = 1;

        // step1: take that element to correct place
        while (i < size)
        {
            int leftIndex = i * 2;
            int rightIndex = i * 2 + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
                return;
        }
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) // O(nLogn)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.del();

    h.print();

    int n = 5;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "After Heapify" << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);
    cout << "After Sorting" << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}