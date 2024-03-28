#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    struct NODE * prev;
    int data;
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

struct NODE * insert_First(struct NODE * head,int data)
{
    struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
    ptr->data = data;
    
    ptr->next = head; 
    return ptr;
    // printf("After inserting %d before the head node, the linked list looks like: \n", data);
    // traverse(ptr);
}

void insert_Bet(struct NODE * p, struct NODE * head, int data)
// ! Here p refers to that node after which we need to insert a new Node
{
    struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;
    printf("After adding %d to the linked list, the list looks like :\n", data);
    traverse(head);
}

void insert_index(struct NODE * head, int data, int index)
{
    struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
    ptr->data = data;

    struct NODE * p = head;
    int i = 0;

    do
    {
        p = p->next;
        i++;
    }
    while(i != index-1);

    ptr->next = p->next;
    p->next = ptr;
    // ptr->prev = p;
    traverse(head);
}

void insert_end(struct NODE * head, int data)
{
    struct NODE * ptr = (struct NODE *)malloc(sizeof(struct NODE));
    ptr->data = data;

    struct NODE * p = head;
    
    while (p->next != NULL)
    {
        p = p->next;
    }
    
    p->next = ptr;
    ptr->next = NULL;
    traverse(head);
}

void main()
{
    system("cls");
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

    // n1 = insert_First(n1, 100);
    traverse(n1);
    // insert_Bet(n3, n1, 88);
    insert_index(n1, 6400, 2);
    insert_end(n1, 69);
}