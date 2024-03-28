#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void show(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(array+i));
    }
    printf("\n");
}

void indDeletion(int *array, int index, int size){
    for (int i = index; i < size-1; i++)
    {
        *(array+i) = *(array+i+1);
    }
}

int main(){
    // printf("Hello world\n");
    int arr[100]={5, 10, 15, 20, 25};
    int index=2, size=5;

    show(arr, size);
    
    indDeletion(arr, index, size);
    size--;
    show(arr, size);

    return 0;
}