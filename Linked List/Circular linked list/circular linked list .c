#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
 
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    
 
    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    ptr->data = data;
    ptr->next = head;
    p->next = ptr;
    
    head = ptr;
    return head;
 
}
 
struct Node * deleteAtFirst(struct Node *head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    // If the list contains only one node
    if (head->next == head) {
        free(head);  // Free the single node
        return NULL; // Return NULL as the list is now empty
    }

    // Traverse to the last node
    struct Node *p = head->next;
    while (p->next != head) {
        p = p->next;
    }

    // At this point, p points to the last node of the circular linked list

    struct Node *temp = head;  // Store the head node (which will be deleted)
    p->next = head->next;      // Point last node's next to the new head (second node)
    head = head->next;         // Move the head pointer to the second node

    free(temp);  // Free the old head node

    return head;
}


int main(){
    
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
    third->data = 6;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;
 

printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);

    head=deleteAtFirst(head);
    head=deleteAtFirst(head);
    printf("Circular Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}
