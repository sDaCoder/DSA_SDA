#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// void createArr(int array[]){
//     for (int i = 0; i < 4; i++)
//     {
//         printf("Enter the element %d\n", i);
//         scanf("%d\t", &array[i]);
//     }
// }

void show(int arr[], int size){
    // This is known as Traversal, i.e., visiting each and every element of the array
    for (int j = 0; j < size; j++)
    {
        printf("%d\t", arr[j]);
    }
    printf("\n");
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
    if (size>=capacity)
    {
        return -1;
        /* code */
    }
    
    for (int i = size-1 ; i >= index ; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index] = element;
    // return 0;
}

int main(){
    // printf("Hello world\n");
    int arr[10]={1, 2, 3, 78};
    int size=4, element=45, capacity=10, index=3;
    // Index= The position where the new element is to be inserted
    // element = The element to be inserted into the array
    // Capacity= here, the capacity of the array is 10
    // createArr(arr);
    show(arr, size);
    indInsertion(arr, size, element, capacity, index);
    if (indInsertion(arr, size, element, capacity, index)!=-1)
    {
    
        size++;
        show(arr, size);
    }
    else
    {
        printf("Insertion Failed\n");
    }
    return 0;
}