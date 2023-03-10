#include<stdio.h>
#include<stdlib.h>

// define the structure of the linked list node
struct Node{
    int data;
    struct Node * next;
};

// set the head pointer to NULL initially
struct Node * head = NULL;

// function to insert a node at the beginning of the linked list
void insert_beg(int val){
    // allocate memory for a new node
    struct Node * temp = (struct Node*) malloc(sizeof(struct Node));
    // set the data for the new node
    temp->data = val;
    // set the next pointer of the new node to the current head of the linked list
    temp->next = NULL;
    if(head == NULL){
        // if the linked list is empty, set the new node as the head
        head =temp;
    }
    else{
        // otherwise, set the new node as the new head of the linked list
        temp->next = head;
        head = temp;
    }
}

// function to insert a node at the end of the linked list
void insert_end(int val){
    // allocate memory for a new node
    struct Node * temp = (struct Node*) malloc(sizeof(struct Node));
    struct Node* current = NULL;

    // set the data for the new node
    temp->data = val;
    // set the next pointer of the new node to NULL
    temp->next = NULL;

    if(head == NULL){
        // if the linked list is empty, set the new node as the head
        head =temp;
    }
    else{
        // otherwise, traverse the linked list to the end and set the next pointer of the last node to the new node
        current = head;
        while(current ->next != NULL){
            current = current-> next;
        }
        current-> next = temp;
    }

}

// function to insert a node at a specified position in the linked list
void insert_pos(int val, int pos){
    // create pointers to the current and previous nodes
    struct Node * current = NULL;
    struct Node * temp = (struct Node *)malloc(sizeof (struct Node));
    int i = 1;

    // set the data for the new node
    temp->data = val;
    // set the next pointer of the new node to NULL
    temp->next = NULL;

    current = head;

    if(pos == 1){
        // if the new node is to be inserted at the beginning of the linked list, set it as the head
        temp-> next = head;
        head = temp;
    }
    else{
        // otherwise, traverse the linked list to the specified position and insert the new node
        while(i < pos){
            current = current -> next;
            i++;
        }
        temp-> next = current ->next;
        current ->next = temp;
    }
}

// function to traverse the linked list and print the values of each node


// Traverses the linked list and prints its elements
void traverse(){
    struct Node * current = NULL;

    // If the list is empty, print a message and return
    if (head == NULL){
        printf("Empty\n");
    }
    else{
        // Traverse the list and print each element separated by tabs
        current = head;
        while(current != NULL){
            printf("%d", current-> data);
            current = current->next;
            printf("\t");
        }
        printf("\n");
    }
}

// Deletes the first element in the linked list
void delete_beg(){
    struct Node * temp = NULL;
    if(head == NULL){
        printf("Empty");
    }
    else {
        // Set the head to the second element and free the memory of the previous head
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Deletes an element at a specified position in the linked list
void delete_pos(int pos){
    struct Node * current  = NULL;
    struct Node * temp  = NULL;
    int i = 1;

    if(pos == 1){
        // If the element to be deleted is the head, set the head to the second element and free the memory of the previous head
        current = head;
        head = head -> next;
        free(current);
    }
    else{
        // Traverse the list to the element before the one to be deleted, set its next pointer to skip over the element to be deleted, and free its memory
        current = head;
        while(i < pos - 1){
            current = current -> next;
            i++;
        }
        temp = current ->next;
        current -> next = temp ->next;
        free(temp);
    }
}

int main(void){
    insert_beg(20);
    insert_beg(10);
    insert_end(40);
    insert_pos(30, 3);
    traverse();
    delete_pos(3);
    traverse();
    return 0;

}
