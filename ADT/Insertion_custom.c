#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct myArray
{
    int total_size;    
    int used_size;    
    int *ptr;
} mA;

void createArr(mA* a, int tSize, int uSize){
    (*a).total_size= tSize;
    (*a).used_size= uSize;
    (*a).ptr = (int*) malloc(tSize* sizeof(int));
}

void setVal(mA *a)
{
    for (int i = 0; i < a->used_size ; i++)
    {
        printf("Enter the value of the element %d\n", i);
        scanf("%d", &((*a).ptr[i]));
    }
}

void show(mA *a){
    for (int i = 0; i < a->used_size ; i++)
    {
        printf("%d  ", a->ptr[i]);
        /* code */
    }
    printf("\n");
}

void indInsertion(mA *a, int total_size, int used_size, int index, int element){
    for (int i = (used_size-1); i >= index; i++)
    {
        a->ptr[i+1]=a->ptr[i];
    }
    a->ptr[index]=element;
    
}

int main(){
    mA arr;
    int uSize, tSize, index, element;
    printf("ENter the total size\n");
    scanf("%d", &tSize);

    printf("ENter the size to be used\n");
    scanf("%d", &uSize);

    printf("ENter the new element and the postion of the new element\n");
    scanf("%d%d", &element, &index);
    
    createArr(&arr, tSize, uSize);
    
    setVal(&arr);

    show(&arr);

    indInsertion(&arr, tSize, uSize, index, element);
    // tSize++;
    show(&arr);

    // printf("Hello world\n");
    return 0;
}
