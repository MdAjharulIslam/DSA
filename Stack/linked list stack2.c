#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* top=NULL;

void linkedListTraversal(struct Node *ptr){
while(ptr != NULL)
{
    printf("Element: %d\n",ptr->data);
    ptr=ptr->next;
}
}



int isEmpty (struct Node* top){
if(top==NULL){
    return 1;
}else{
    return 0;
}
}

int isFull(struct Node* top){
struct Node* p=(struct Node*)malloc(sizeof(struct Node));
if(p==NULL){
    return 1;
}else{
    return 0;
}
}

struct Node* push(struct Node* top,int x){
if(isFull (top)){
    printf("stack is overflow!\n");
}else{
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=x;
    n->next=top;
    top=n;
    return top;
}
}

int pop(struct Node* tp) {
    if(isEmpty(tp)) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        struct Node* n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main(){


top=push(top,70);
top=push(top,80);
top=push(top,90);
linkedListTraversal(top);

int element =pop(top);
printf("poped element is %d\n",element);
linkedListTraversal(top);
    return 0;
}
