#include <stdio.h>

int size = 10;

void sort() {
    int arr[] = {70, 55, 67, 3, 25, 45, 6, 78, 39, 30};

    printf("The sorted elements are: ");

    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    sort();
    printf("\n");
    return 0;
}
