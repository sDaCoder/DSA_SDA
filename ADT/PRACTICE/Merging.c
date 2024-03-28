#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void show(int* arr1, int size1)
{
    for (int i = 0; i < size1; i++)
    {
        printf("%d\t", arr1[i]);
    }
    printf("\n\n");
}

// ***************MERGING TWO ARRAYS***************

void merge(int* arr1, int* arr2, int size1, int size2)
{
    int sum_size = size1 + size2;
    int arr3[sum_size];

    // TODO COPYING THE ARRAY 1 TO ARRAY 3
    for (int i = 0; i < size1; i++)
    {
        arr3[i] = arr1[i];
    }
    
    // TODO: COPYING THE ARRAY 2 TO ARRAY 3
    for (int i = 0, j = size1; i < size2 && j < sum_size; i++, j++)
    {
        arr3[j] = arr2[i];
    }
    
    // TODO: DISPLAYING THE MERGED ARRAY
    show(arr3, sum_size);
    
}

int main(){
    system("cls");
    // printf("Hello world\n");
    // printf("%d\n\n", sizeof(arr1)/sizeof(int));
    int arr1[] = {1, 38, 389};
    int size1 = sizeof(arr1)/sizeof(int);

    int arr2[] = {5, 238, 102};
    int size2 = sizeof(arr2)/sizeof(int);
    
    // show(arr1, size1);
    merge(arr1, arr2, size1, size2);
    
    return 0;
}                                