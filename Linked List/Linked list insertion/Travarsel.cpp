#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void linkedlisttraversel(struct Node* ptr) {
    while (ptr != NULL) {
        printf(" Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
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

    return 0;
}

