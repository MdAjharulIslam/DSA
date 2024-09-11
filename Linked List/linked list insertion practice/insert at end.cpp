#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
   struct  Node* next;
};
//function for traversal
void traversal(struct Node* ptr){
while(ptr!=NULL){
    printf("the elements : %d\n",ptr->data);
   ptr= ptr->next;
}
}


//funtion for insert at end
struct Node* insertatend(struct Node* head,int data){
struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
struct Node* p=head;

while(p->next!=NULL){
    p=p->next;
}
ptr->data=data;
p->next=ptr;
return head;
}
int  main(){
 struct Node* head;
struct Node* second;
struct Node* third;
struct Node* fourth;
struct Node* fifth;

head=(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));
fourth=(struct Node*)malloc(sizeof(struct Node));
fifth=(struct Node*)malloc(sizeof(struct Node));

head->data=10;
head->next=second;

second->data=20;
second->next=third;

third->data=30;
third->next=fourth;

fourth->data=40;
fourth->next=fifth;

fifth->data=50;
fifth->next=NULL;
//for traversal
traversal(head);
//for insertion at the end
head=insertatend(head,2000);
traversal(head);

return 0;
}
