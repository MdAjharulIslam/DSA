#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to traverse the linked list forward
void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to traverse the linked list backward
void linkedListReverseTraversal(struct Node* ptr) {
    // Move to the last node
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Traverse backward from the last node
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

// Function to insert a node at the head of the doubly linked list
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if (head != NULL) {
        head->prev = ptr;
    }

    return ptr;  // New head node
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;

    ptr->data = data;
    ptr->next = NULL;

    // Case: If the list is empty, make the new node the head
    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }

    // Traverse to the end of the list
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

// Function to insert a node at a specific index in the doubly linked list
struct Node* insertAtIndex(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;

    // Traverse to the node just before the index
    while (i != index - 1) {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;

    if (p->next != NULL) {
        p->next->prev = ptr;
    }

    p->next = ptr;

    return head;
}

// Function to insert a node after a given node in the doubly linked list
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    ptr->prev = prevNode;

    if (prevNode->next != NULL) {
        prevNode->next->prev = ptr;
    }

    prevNode->next = ptr;

    return head;
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second
    head->data = 7;
    head->prev = NULL;
    head->next = second;

    // Link second and third
    second->data = 11;
    second->prev = head;
    second->next = third;

    // Link third and fourth
    third->data = 10;
    third->prev = second;
    third->next = fourth;

    // Link fourth and fifth
    fourth->data = 30;
    fourth->prev = third;
    fourth->next = fifth;

    // Terminate the list at the fifth node
    fifth->data = 66;
    fifth->prev = fourth;
    fifth->next = NULL;

    // Traverse and print the linked list
    printf("Original List (Forward):\n");
    linkedListTraversal(head);

    // Insert at the head and print the updated list
    cout << "Linked list after head insertion:\n";
    head = insertAtFirst(head, 56);
    linkedListTraversal(head);

    // Insert at a specific index and print the updated list
    cout << "Linked list after index insertion:\n";
    head = insertAtIndex(head, 100, 1);
    linkedListTraversal(head);

    // Insert at the end and print the updated list
    cout << "Linked list after inserting at the end:\n";
    head = insertAtEnd(head, 22);
    linkedListTraversal(head);

    // Insert after a specific node (in this case, after the third node) and print the updated list
    cout << "Linked list after insertion after third node:\n";
    head = insertAfterNode(head, third, 44);
    linkedListTraversal(head);

    // Traverse the list in reverse to ensure doubly linked list is set up correctly
    cout << "Reverse Traversal:\n";
    linkedListReverseTraversal(head);

    return 0;
}
