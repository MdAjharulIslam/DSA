#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
//function for a traversel
void linkedlisttraversel(struct Node* ptr) {
    while (ptr != NULL) {
        printf(" Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//function for insert in head
 struct Node*insertatfirst(struct Node *head, int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
 }

//function for insert in end
struct Node* insertatend(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   
    struct Node* p = head;
     
    while (p->next != NULL) {
        p = p->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    p->next = ptr;
    return head;
}



//function for insert in a specific index

 struct Node* insertatindex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}






//function for insert in after
struct Node* insertatafter(struct Node* head,  struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next=prevNode->next;
   prevNode->next=ptr;


    return head;
}
int main() {

    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));
    fifth = (struct Node*) malloc(sizeof(struct Node));

    // Link first and second
    head->data = 7;
    head->next = second;

    // Link second and third
    second->data = 11;
    second->next = third;

    // Link third and fourth
    third->data = 10;
    third->next = fourth;


    // Link fourth and fifth
    fourth->data = 30;
    fourth->next = fifth;


    // Terminate the list at the fourth node
    fifth->data = 66;
    fifth->next = NULL;

    // Traverse and print the linked list
    linkedlisttraversel(head);
    
    //insertion in the head
    cout<<"linked list after head insertion"<<endl;
    head=insertatfirst(head,56);
    linkedlisttraversel(head);

    //insertion in the index
   cout<<"linked list after index insertion"<<endl;
   head=insertatindex(head,100,1);
    linkedlisttraversel(head);

    //insert at end
    cout<<"linked list after insert in the end"<<endl;
    head=insertatend(head,22);
    linkedlisttraversel(head);

    //insert at after node
    cout<<"linked list after insert in the after node"<<endl;
    head=insertatafter(head,third,44);
    linkedlisttraversel(head);
    return 0;
}
