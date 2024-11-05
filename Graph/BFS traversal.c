#include<stdio.h>
#include<stdlib.h>

// Define the queue structure
struct queue {
    int size;
    int f;      // Front index
    int r;      // Rear index
    int* arr;   // Pointer to dynamically allocated array
};

// Function to check if the queue is empty
int isEmpty(struct queue *q) {
    if (q->r == q->f) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is full
int isFull(struct queue *q) {
    if (q->r == q->size - 1) {
        return 1;
    }
    return 0;
}

// Function to enqueue an element to the queue
void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    }
    else {
        q->r++;
        q->arr[q->r] = val;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    }
    else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    // Initialize the queue
    struct queue q;
    q.size = 400;  // Queue size
    q.f = q.r = 0; // Initialize front and rear to 0
    q.arr = (int*) malloc(q.size * sizeof(int)); // Dynamically allocate memory for queue

    // Graph represented as an adjacency matrix (7 nodes)
    int a[7][7] = {
        {0,1,1,1,0,0,0},  // Connections from node 0
        {1,0,1,0,0,0,0},  // Connections from node 1
        {1,1,0,1,1,0,0},  // Connections from node 2
        {1,0,1,0,1,0,0},  // Connections from node 3
        {0,0,1,1,0,1,1},  // Connections from node 4
        {0,0,0,0,1,0,0},  // Connections from node 5
        {0,0,0,0,1,0,0}   // Connections from node 6
    };

    // Array to keep track of visited nodes
    int visited[7] = {0,0,0,0,0,0,0};
    int i = 0;  // Start BFS from node 0

    // Mark the starting node as visited and enqueue it
    visited[i] = 1;
    printf("%d ", i);
    enqueue(&q, i);

    // BFS loop: Continue until the queue is empty
    while (!isEmpty(&q)) {
        int node = dequeue(&q);  // Dequeue the current node

        // Explore all adjacent nodes of the current node
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {  // Check if there's an edge and if the node is unvisited
                printf("%d ", j);  // Print the newly visited node
                visited[j] = 1;    // Mark the node as visited
                enqueue(&q, j);    // Enqueue the node for further exploration
            }
        }
    }

    return 0;
}
