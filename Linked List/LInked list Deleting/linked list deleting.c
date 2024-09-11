#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
struct Node *deleteFirst(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}



// Case 2: Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index) {
    if (index == 0) {
        return deleteFirst(head);
    }
    
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++) {
        if (q == NULL) {
            return head; // index out of bounds
        }
        p = p->next;
        q = q->next;
    }
    
      
    
    p->next = q->next;
    free(q);
    return head;
}

//Case 3: Deleting the last element
struct Node *deleteAtLast(struct Node *head) {
    if (head == NULL) {
        return NULL; // Empty list
    }
    
    if (head->next == NULL) {
        free(head);
        return NULL; // Only one element
    }
    
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

// Case 4: Deleting the element with a given value from the linked list
struct Node *deleteByValue(struct Node *head, int value) {
    if (head == NULL) {
        return NULL; // Empty list
    }
    
    if (head->data == value) {
        return deleteFirst(head); // Value at the head
    }
    
    struct Node *p = head;
    struct Node *q = head->next;
    while (q != NULL && q->data != value) {
        p = p->next;
        q = q->next;
    }
    
    if (q != NULL) {
        p->next = q->next;
        free(q);
    }
    
    return head;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // Uncomment the following lines to test different cases:
    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2); // For deleting element at index 2
    head = deleteAtLast(head); // For deleting the last element
    // head = deleteByValue(head, 3); // For deleting element with value 3

    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    // Free the remaining nodes
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
