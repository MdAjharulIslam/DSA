#include <iostream>
using namespace std;

class MaxHeap
{
public:
    int* heap;
    int capacity;
    int size;

    // Constructor to initialize the heap
    MaxHeap(int cap)
    {
        capacity = cap;
        size = 0;
        heap = new int[capacity];  // Dynamically allocate memory for the heap
    }



    // Function to heapify the tree (maintains heap property)
    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;  // Left child index
        int right = 2 * index + 2; // Right child index

        // Compare with left child
        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        // Compare with right child
        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        // If largest is not root, swap and heapify the affected subtree
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

    // Insert a new element to the heap
    void insert(int val)
    {
        if (size >= capacity)
        {
            cout << "Heap is full!" << endl;
            return;
        }

        // Add the new element to the end of the heap
        heap[size] = val;
        int index = size;
        size++;

        // Move the element to its correct position
        while (index > 0 && heap[(index - 1) / 2] < heap[index])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Delete the root element (max element)
    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        // Move the last element to the root
        heap[0] = heap[size - 1];
        size--;

        // Heapify the root element
        heapify(0);
    }

    // Function to sort the heap (heap sort)
    void heapSort()
    {
        int originalSize = size;  // Save original size for later printing

        // Build the heap (heapify all non-leaf nodes)
        for (int i = originalSize / 2 - 1; i >= 0; --i)
        {
            heapify(i);
        }

        // Extract elements from the heap one by one
        for (int i = originalSize - 1; i >= 0; --i)
        {
            // Swap current root with the last element
            swap(heap[0], heap[i]);

            // Heapify the reduced heap
            size--;  // Reduce the size after moving the root to the end
            heapify(0);
        }

        size = originalSize;  // Restore the size after heap sort
    }

    // Print the heap
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
    MaxHeap maxHeap(10);  // Create a heap with a capacity of 10

    // Insert elements into the heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(15);

    cout << "Heap after insertion: ";
    maxHeap.printHeap();

    // Delete the root element (max element)
    maxHeap.deleteRoot();
    cout << "Heap after deleting root: ";
    maxHeap.printHeap();

    // Perform heap sort
    maxHeap.heapSort();
    cout << "Heap after heap sort: ";
    maxHeap.printHeap();

    return 0;
}
