#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int *heap;
    int capacity;
    int size;

    MaxHeap(int cap)
    {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    // Function to heapify a subtree with root at given index
    void heapify(int index, int n)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Compare with left child
        if (left < n && heap[left] > heap[largest])
        {
            largest = left;
        }

        // Compare with right child
        if (right < n && heap[right] > heap[largest])
        {
            largest = right;
        }

        // If largest is not root, swap and continue heapifying
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify(largest, n);
        }
    }

    // Function to build a max heap
    void buildHeap(int n)
    {
        // Start from the last non-leaf node and heapify each node
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(i, n);
        }
    }


    
    // Function to add elements to the heap for demonstration
    void addElements(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            heap[i] = arr[i];
        }
        size = n;
    }

    // Heap sort function
    void heapSort()
    {
        // Build a max heap
        buildHeap(size);

        // One by one extract elements from the heap
        for (int i = size - 1; i >= 0; i--)
        {
            // Move current root to end
            swap(heap[0], heap[i]);

            // Heapify the reduced heap
            heapify(0, i);
        }
    }


    // Function to print the sorted array
    void printHeap()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap maxHeap(10);

    // Example array to be sorted
    int arr[] = {10, 3, 15, 20, 50, 8, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Add elements to the heap
    maxHeap.addElements(arr, n);

    // Perform heap sort
    maxHeap.heapSort();

    cout << "Array after heap sort: ";
    maxHeap.printHeap();

    return 0;
}
