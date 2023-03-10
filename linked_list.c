/*An implementation of a linked list in c language*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
            int data;
            struct Node *next;
};

struct Node *head = NULL;

void delete_beg(){
    struct Node *temp = NULL;
    if(head == NULL){
            printf("Empty");
       }
    else{
        temp = head;
        head = head->next;
        free(head);
    }
}
void delete_end(){
    //body
}
void delete_pos(int pos){
    int i = 1;
    struct Node *temp = NULL;
    struct Node *current = NULL;
    if(pos == 1){
        current = head;
        head = head-> next;
        free(current);
    }
    else{
        current = head;
        while(i < pos-1){
            current = current-> next;
            i++;
            }
                        temp = current -> next;
                        current->next=temp->next;
                        free(temp);
    }
}
void insert_beg(int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        temp-> next = head;
        head = temp;
    }
}
void insert_end(int val){
    struct Node *current = NULL;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
            current = head;
            while(current->next!= NULL){
                current = current-> next;
            }
    current-> next = temp;
    }

}
void insert_pos(int val, int pos){
    int i = 1;
    struct Node *current = NULL;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    current = head;
    if (pos == 1){
        temp-> next = head;
        head = temp;}
    else{
         while (i < pos - 1){
        current = current-> next;
        i++;
        }
        temp->next = current-> next;
        current->next = temp;
    }
}
void traverse(){
    struct Node *current = NULL;
    if(head == NULL){
       printf("Empty\n");
    }
    else{
        current = head;
        while(current!= NULL){
            printf("%d\t", current -> data);
            current = current -> next;
        }
        printf("\n");
    }
}
void search(int key){
    //body
}

int main(void){
    insert_beg(20);
    insert_beg(10);
    insert_end(40);
    insert_pos(30, 3);
    traverse();
    delete_end();
    delete_pos(3);
    traverse();
    //traverse();
   // search(10);
    return 0;
}
