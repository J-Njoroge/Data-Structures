#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = previous; // Reverse the link
        previous = current; // Move pointers one position ahead
        current = next;
    }
    *head = previous; // Update the head pointer
}

// Main function
int main() {
    // Initialize a linked list with 3 nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Print the original list
    printf("Original list:\n");
    printList(head);

    // Reverse the linked list
    reverseList(&head);

    // Print the reversed list
    printf("Reversed list:\n");
    printList(head);

    return 0;
}
