#include<stdio.h>
#define SIZE 10

int count = 10;
int data[SIZE] = {10, 5, 20, 15, 30, 35, 25, 60, 80, 90};

void traversal(void) {
    for(int i = 0; i < count; i++) {
        printf("%d \t", data[i]);
    }
    printf("\n");
}

void search(int key){
    for(int i = 0; i < count; i++){
        if(key == data[i]){
            printf("The value has been found.\n");
            break;
        }
    if(i == count){
        printf("The value has not been found.\n");
        }
    }
}
void delete_item(int index){
    for(int i = index; i < count - 1; i++){
        data[i] = data[i + 1];
    }
    count -= 1;
    traversal();
}
void insertion(int value, int index){
    if(count < SIZE){
        for(int i = count -1; i >= index; i--){
            data[i + 1] = data[i];
        }
        data[index] = value;
        count = count + 1;
        traversal();
    }
    else
        printf("The array is full.\n");
}
void IsEmpty(){
if(count == 0)
    printf("It is empty.\n");
else
    printf("It is not empty.\n");
}
void IsFull(){
if(count == 0)
    printf("It is full.\n");
else
    printf("It is not full.\n");
}
int main(){

delete_item(1);
delete_item(2);
delete_item(0);
search(10);
search(60);
insertion(100,1);
IsFull();
IsEmpty();
return 0;
}

