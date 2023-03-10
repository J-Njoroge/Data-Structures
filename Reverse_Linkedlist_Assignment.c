#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}


int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Original list:\n");
    printList(head);

    reverseList(&head);
    printf("Reversed list:\n");
    printList(head);

    return 0;
}
