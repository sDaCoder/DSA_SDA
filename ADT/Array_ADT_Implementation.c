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
    // (*a).total_size= tSize;
    // (*a).used_size= uSize;
    // (*a).ptr = (int*) malloc(tSize* sizeof(int));

    // 👆🏻THe same thing can be written in the manner given below👇🏻
    a->total_size= tSize;
    a->used_size= uSize;
    a->ptr = (int*) malloc(tSize* sizeof(int));
    // 👆🏻It allocates the memory from the heap and stores the address of the first element of the array
}

void setVal(mA *a){
    int n;
    for (int i = 0; i < (a->used_size); i++)
    {
        printf("ENter the value of the Element %d\n", i);
        scanf("%d", &n);
        ((*a).ptr)[i]= n;
    }
}
void show(mA *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}


int main(){
    // printf("Hello world\n");
    mA marks;    
    createArr(&marks, 10, 2);
    printf("Loading the values as per your choice\n");
    setVal(&marks);

    printf("THe marks of the student are displayed below\n");
    show(&marks);
    return 0;
}