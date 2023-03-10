#include<stdio.h>

int size = 8;

void  sort(){

int num[] = {64, 25 , 12, 22, 11, 9, 41, 2};

    printf("Sorted elements are: ");

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){//for comparing one element to another
         if(num[i] > num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        printf("%d \t", num[i]);
    }
printf("\n");
}

int main()
{
    sort();
    return 0;
    printf("\n");
}
