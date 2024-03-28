#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int data;
    struct NODE * prev;
    struct NODE * next;
};

void traverse(struct NODE *head)
{
    struct NODE * ptr = head;
    do
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    } 
    while (ptr != NULL);
    printf("\n\n");
}
    
void ulta_traverse(struct NODE * end)
{
    struct NODE * ptr = end;
    do
    {
        printf("%d  ", ptr->data);
        ptr = ptr->prev;
    }
    while (ptr != NULL);
    printf("\n\n");
}

int main()
{
    struct NODE * n1 = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE * n2 = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE * n3 = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE * n4 = (struct NODE *)malloc(sizeof(struct NODE));

    (n1)->data = 23;
    (n1)->next = n2;
    (n1)->prev = NULL;

    (n2)->data = 34;
    (n2)->next = n3;
    (n2)->prev = n1;

    (n3)->data = 45;
    (n3)->next = n4;
    (n3)->prev = n2;

    (n4)->data = 96;
    (n4)->next = NULL;
    (n4)->prev = n3;

    printf("The linked list in the forward direction is :\n");
    traverse(n1);
    
    printf("The linked list in the backward direction is :\n");
    ulta_traverse(n4);

    return 0;
}