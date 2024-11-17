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
    void heapify(int index)
    {

        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }

    void insert(int val)
    {

        if (size >= capacity)
        {
            cout << "this heap is full" << endl;
            return;
        }

        heap[size] = val;
        int index = size;
        size++;

        while (index > 0 && heap[(index - 1) / 2] < heap[index])
        {

            swap(heap[(index - 1) / 2], heap[index]);

            index = (index - 1) / 2;
        }
    }

    void deleteHeap()
    {

        if (size == 0)
        {
            cout << "Heap is Empty" << endl;
            return;
        }

        heap[0] = heap[size - 1];
        size--;
        heapify(0);
    }

void heapSort(){
    int originalSize=size;
    for(int i=originalSize/2-1;i>=0;i--){
        heapify(i);

    }
    for(int i=originalSize-1;i>=0;i--){
        swap(heap[0],heap[i]);
        size--;
        heapify(0);
    }
    size=originalSize;
}


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

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(3);
    maxHeap.insert(15);
    maxHeap.insert(50);

    cout << "Heap after insertion: ";
    maxHeap.printHeap();

    maxHeap.deleteHeap();
    cout << "Heap after deletetion: ";

    maxHeap.printHeap();

    maxHeap.heapSort();
    cout<<"Heap after Heap sort: ";
    maxHeap.printHeap();

    return 0;
}
