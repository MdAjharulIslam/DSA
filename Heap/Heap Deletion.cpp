#include <iostream>
using namespace std;

class MaxHeap {
public:
    int* heap;
    int capacity;
    int size;

    // Constructor to initialize the heap
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];  // Dynamically allocate memory for the heap
    }

    // Destructor to clean up the allocated memory
    ~MaxHeap() {
        delete[] heap;  // Clean up dynamically allocated memory
    }

    // Function to maintain the heap property (heapify the subtree rooted at index)
    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;  // Left child index
        int right = 2 * index + 2; // Right child index

        // Compare with left child
        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        // Compare with right child
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        // If the largest element is not the current root, swap and heapify the affected subtree
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

    // Delete the root element (max element)
    void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        // Move the last element to the root
        heap[0] = heap[size - 1];
        size--;

        // Heapify the root element to maintain heap property
        heapify(0);
    }

    // Print the heap elements
    void printHeap() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10);  // Create a heap with a capacity of 10

    // Example elements for the heap
    maxHeap.heap[0] = 50; maxHeap.size++;
    maxHeap.heap[1] = 30; maxHeap.size++;
    maxHeap.heap[2] = 20; maxHeap.size++;
    maxHeap.heap[3] = 15; maxHeap.size++;
    maxHeap.heap[4] = 10; maxHeap.size++;
    maxHeap.heap[5] = 8; maxHeap.size++;
    maxHeap.heap[6] = 16; maxHeap.size++;

    cout << "Initial Heap: ";
    maxHeap.printHeap();

    // Delete the root element (max element)
    maxHeap.deleteRoot();
    cout << "Heap after deleting root: ";
    maxHeap.printHeap();

    // Delete the root element again
    maxHeap.deleteRoot();
    cout << "Heap after another deletion: ";
    maxHeap.printHeap();

    return 0;
}
