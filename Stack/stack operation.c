#include<stdio.h>
#include<stdlib.h>

struct stack{
        int size;
        int top;
        int  *arr;
};
int isFull(struct stack* ptr){
if(ptr->top==ptr->size-1){
    return 1;
}
else{
    return 0;
}
}


int isEmpty(struct stack* ptr){
if(ptr->top==-1){
    return 1;
}
else{
    return 0;
}
}


void push( struct stack* ptr,int val){

    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n",val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;

    }
}


int pop( struct stack* ptr){

    if(isEmpty(ptr)){
        printf("Stack underflow! Cannot pop from the stack\n");
         return -1;
    }else{
        int val=ptr->arr[ptr->top];

        ptr->top--;
        return val;

    }
}


int main(){
struct stack *sp=(struct stack* )malloc(sizeof(struct stack));
sp->size=10;
sp->top=-1;
sp->arr=(int *)malloc(sp->size * sizeof(int));

printf("stack has been created sucessfully\n");

printf("Before pushing ,Full %d\n",isFull(sp));
printf(" Before pushing ,Empty%d\n",isEmpty(sp));

push(sp,56);
push(sp,5);
push(sp,66);
push(sp,46);
push(sp,55);
push(sp,10);
push(sp,12);
push(sp,30);
push(sp,11);
push(sp,24); //--->pushed 10 value
push(sp,40);// stack oberflow since the size of of the stack is 10
printf("After pushing ,Full %d\n",isFull(sp));
printf(" After pushing ,Empty%d\n",isEmpty(sp));

printf("Poped %d fron the stack\n",pop(sp)); //1st in last out
printf("Poped %d fron the stack\n",pop(sp)); //1st in last out
printf("Poped %d fron the stack\n",pop(sp)); //1st in last out
printf("Poped %d fron the stack\n",pop(sp)); //1st in last out
 
 printf("sucessfully poped in this stack\n");
    return 0;
}
