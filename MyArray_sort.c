#include<stdio.h>

int size = 10;

void sort(){

int arr[]={5, 6, 2, 1, 8, 4, 7, 9, 3, 10};

 printf("The sorted elements are: ");

 for(int i = 0; i < size; i++){
    for(int j = i + 1; j < size; j++){
        if(arr[i] > j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

 }
 for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
 printf("\n");
 }
}
int main(){
sort();
printf("\n");
return 0;
}
