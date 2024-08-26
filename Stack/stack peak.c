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

int peek(struct stack* sp,int i){
    int arrayInd=sp->top-i+1;
    if(arrayInd<0){
        printf("Not a valid position for stack\n");
    }else{
return sp->arr[arrayInd];

    }
}
int main(){
struct stack *sp=(struct stack* )malloc(sizeof(struct stack));
sp->size=50;
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
push(sp,24); 
push(sp,5);
//printing value from the stack
for(int j=1;j<=sp->top+1;j++)
{
printf("the value at position %d is %d\n",j,peek(sp ,j));
}
    return 0;
}
