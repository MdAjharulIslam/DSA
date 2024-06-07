#include<stdio.h>

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int size, int element, int capacity, int index) {
    if (size >= capacity) {
        return -1;
    }
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main() {
    int arr[100] = {1, 10, 20, 30, 40};
    int size = 5; 
    int element = 50;
    int index = 3;
    display(arr, size);
    
    insertElement(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    
    return 0;
}


    