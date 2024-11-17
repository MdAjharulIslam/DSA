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

    // Insert a new element into the heap
    void insert(int val) {
        if (size >= capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        // Add the new element to the end of the heap
        heap[size] = val;
        int index = size;
        size++;

        // Move the element to its correct position to maintain heap property
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
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

    // Insert elements into the heap
    maxHeap.insert(50);
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(10);
    maxHeap.insert(8);
    maxHeap.insert(16);

    cout << "Heap after insertion: ";
    maxHeap.printHeap();

    return 0;
}
