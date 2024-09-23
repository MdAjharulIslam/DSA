#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue *q) {
    return (q->f == q->r);
}

int isFull(struct queue *q) {
    return (q->r == q->size - 1);
}

void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    } else {
        if (q->f == -1) q->f = 0; // Initialize front if it was empty
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    } else {
        a = q->arr[q->f];
        q->f++;
        if (q->f > q->r) { // Reset queue if it becomes empty
            q->f = q->r = -1;
        }
    }
    return a;
}

int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 4;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    // Enqueue a few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    printf("Dequeuing element %d\n", dequeue(q));
    enqueue(q, 45);
    enqueue(q, 50);
    enqueue(q, 55); // Adjust values as needed

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    if (isFull(q)) {
        printf("Queue is full\n");
    }

    // Clean up memory
    free(q->arr);
    free(q);
    
    return 0;
}
