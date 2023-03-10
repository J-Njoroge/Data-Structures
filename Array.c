#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void traverse() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    int element;
    if (size >= MAX_SIZE) {
        printf("Error: Array is full. Insertion failed.\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    arr[size] = element;
    size++;
    printf("New element inserted: %d\n", element);
}

void delete() {
    int index;
    if (size == 0) {
        printf("Error: Array is empty. Deletion failed.\n");
        return;
    }
    printf("Enter the index to delete: ");
    scanf("%d", &index);
    if (index < 0 || index > size) {
        printf("Error: Invalid index. Deletion failed.\n");
        return;
    }
    int deleted_element = arr[index];
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];//Why are we doing this?
    }
    size--;
    printf("Deleted element: %d\n", deleted_element);
}

void sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted.\n");
    traverse();
}

void update() {
    int index, element;

    printf("Enter the index to update: ");
    scanf("%d", &index);
    if (index < 0 || index >= size) {
        printf("Error: Invalid index. Updating failed.\n");
        return;
    }
    printf("Enter the new element: ");
    scanf("%d", &element);
    arr[index] = element;
    printf("Array updated.\n");
    traverse();
}

int main() {
    int choice;
    while (1) {
        printf("Array operations:\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Sort\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                sort();
                break;
            case 5:
                update();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
