#include<stdio.h>
#include<stdlib.h>

struct dequeue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct dequeue *q){
    if(q->r == -1 && q->f == -1){
        return 1;
    }
    return 0;
}

int isFull(struct dequeue *q){
    if((q->f == 0 && q->r == q->size-1) || (q->f == q->r+1)){
        return 1;
    }
    return 0;
}

void enqueueRear(struct dequeue *q, int val){
    if(isFull(q)){
        printf("This DEqueue is full\n");
    }
    else{
        if(q->f == -1){
            q->f = q->r = 0;
        }
        else if(q->r == q->size-1 && q->f != 0){
            q->r = 0;
        }
        else{
            q->r++;
        }
        q->arr[q->r] = val;
        printf("Enqueued element at rear: %d\n", val);
    }
}

void enqueueFront(struct dequeue *q, int val){
    if(isFull(q)){
        printf("This DEqueue is full\n");
    }
    else{
        if(q->f == -1){
            q->f = q->r = 0;
        }
        else if(q->f == 0){
            q->f = q->size-1;
        }
        else{
            q->f--;
        }
        q->arr[q->f] = val;
        printf("Enqueued element at front: %d\n", val);
    }
}

int dequeueFront(struct dequeue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This DEqueue is empty\n");
    }
    else{
        a = q->arr[q->f];
        if(q->f == q->r){
            q->f = q->r = -1;
        }
        else if(q->f == q->size-1){
            q->f = 0;
        }
        else{
            q->f++;
        }
    }
    return a;
}

int dequeueRear(struct dequeue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This DEqueue is empty\n");
    }
    else{
        a = q->arr[q->r];
        if(q->f == q->r){
            q->f = q->r = -1;
        }
        else if(q->r == 0){
            q->r = q->size-1;
        }
        else{
            q->r--;
        }
    }
    return a;
}

int main(){
    struct dequeue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size * sizeof(int));
    
    enqueueRear(&q, 12);
    enqueueRear(&q, 15);
    enqueueRear(&q, 1);
    
    enqueueFront(&q, 9);
    enqueueFront(&q, 8);
    
    printf("Dequeuing element from front: %d\n", dequeueFront(&q));
    printf("Dequeuing element from front: %d\n", dequeueFront(&q));

    printf("Dequeuing element from rear: %d\n", dequeueRear(&q));
    printf("Dequeuing element from rear: %d\n", dequeueRear(&q));

    enqueueRear(&q, 45);
    enqueueFront(&q, 7);

    if(isEmpty(&q)){
        printf("DEqueue is empty\n");
    }
    if(isFull(&q)){
        printf("DEqueue is full\n");
    }

    return 0;
}
