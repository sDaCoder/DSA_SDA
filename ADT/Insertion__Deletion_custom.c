#include "suprava.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

// !CREATING AN ARRAY IN THE HEAP DATA STRUCTURE

typedef struct Deletion_custom{
    int total;
    int use;
    int *ptr;
} Dc;

void create(Dc* a, int t){
    (*a).total=t;
    (*a).ptr = (int *)malloc((t)*sizeof(int));    
}

void setVal(Dc* a, int u){
    (*a).use=u;
    for (int i = 0; i < u; i++)
    {
        printf("Enter the value of the element %d\n", i);
        scanf("%d", &(*((*a).ptr+i)));
    }
    
}

void show(Dc* a, int u){
    (*a).use=u;
    for (int i = 0; i < u; i++)
    {
        printf("%d\t", *((*a).ptr+i));
    }
    printf("\n");
}

// ! INSERTING AN ELEMENT IN AN ARRAY (IN HEAP)

void indInsertion(Dc* a, int u, int index, int element){
    (*a).use = u;
    for (int i = u-1 ; i >= index; i--)
    {
        *((*a).ptr+i+1) = *((*a).ptr+i);
    }
    *((*a).ptr+index) = element;
    
    printf("Insertion of the elements is done!!\n");
}

// ! DELETION IN AN ARRAY (HEAP)

void indDeletion(Dc *a, int index, int u){
    a->use=u;
    for (int i = index; i < u-1; i++)
    {
        *((*a).ptr+i) = *((*a).ptr+i+1);
    }
    
    printf("Deletion of the elements is done!!\n");   
}

int main(){
    system("cls");
    Dc array;
    int u ; //USED SIZE
    int t ; // TOTAL SIZE

    printf("Enter the total size if the array\n");
    scanf("%d", &t);

    printf("Enter the number of elements to be used in the array\n");
    scanf("%d", &u);

    
    create(&array, t);

    setVal(&array, u);

    show(&array, u);

    
    int iIndex, element;
    printf("ENter the new element and the position where it is to be inserted\n");
    scanf("%d", &element);
    scanf("%d", &iIndex);

    indInsertion(&array, u, iIndex, element);
    // INSERTION PROCESSING

    u++;
    show(&array, u);

    int dIndex;
    printf("Enter the position where the element is to be deleted\n");
    scanf("%d", &dIndex);

    indDeletion(&array, dIndex, u);
    // DELETION PROCESSING

    u--;
    show(&array, u);

    return 0;
}
