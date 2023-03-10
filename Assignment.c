#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // Set the data of the new node
    new_node->data = new_data;

    // Set the next pointer of the new node to the current head
    new_node->next = (*head_ref);

    // Set the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head_ref) {
    struct Node *prev_node = NULL, *current_node = *head_ref, *next_node = NULL;

    // Traverse the list and reverse the links between nodes
    while (current_node != NULL) {
        next_node = current_node->next;   // Save the next node
        current_node->next = prev_node;  // Reverse the link to the previous node
        prev_node = current_node;        // Move to the next pair of nodes

    }
