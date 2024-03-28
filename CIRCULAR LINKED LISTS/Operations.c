#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Insertion
{
    int data;
    struct Insertion *next;
}node;

void traverse(node * head)
{
    node * p = head;

    // ? HERE, WHILE LOOP IS USED
    // printf("%d\t", head->data);
    // p = p->next;
    // while(p != head)
    // {
    //     printf("%d\t", p->data);
    //     p = p->next;
    // }
    
    // ? HERE, DO-WHILE LOOP IS USED👇🏻
    do
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    while(p != head);

    printf("\n\n");
}

node * insertAtFirst(int data, node * head) 
{
    node * p = head;
    p->data = data;
    node * ptr = (node*)malloc(sizeof(node));

    do
    {
        p = p->next;
    }
    while(p != head);

    // ! NOW THE P POINTER POINTS THE LAST NODE OF THE CIRCULAR LINKED LIST
}

    
    


int main(){
    system("cls");
    // printf("Hello world\n");
    node* head;
    node* second;
    node* third;
    node* fourth;
    node* fifth;

    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));
    fifth = (node*)malloc(sizeof(node));

    head->data = 193;
    head->next = second;

    second->data = 1003;
    second->next = third;

    third->data = 202;
    third->next = fourth;

    fourth->data = 482;
    fourth->next = fifth;

    fifth->data = 8292;
    fifth->next = head;

    traverse(head);
    
}