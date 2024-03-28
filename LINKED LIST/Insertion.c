#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// TODO: LIMITATIONS OF USING AN ARRAY:
    // ! A void has to be made to insert an element.
    // ! Creating a void causes the rest of the elements to shift to their adjacent right.
    // ! Time complexity: O(no. of elements shifted)

typedef struct Insertion
{
    int data;
    struct Insertion *next;
}In;

void traverse(In* ptr){
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);        
        ptr = ptr->next;
    }
    printf("\n\n");
}

In* insertAtFirst(In* head, int data)
{
    In* ptr = (In*)malloc(sizeof(In));

    // ! ALL THE ELEMENTS OF THE STRUCT INSERTION DATA TYPE IS ACCESSED BY THE POINTER
    
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

void insertAtPosition(In* head, int data, int index)
{
    In* ptr = (In*)malloc(sizeof(In));
    ptr->data = data;
    In* p = head;
    int i = 0;

    // ! In this while loop, we take the pointer 'p' to that index where the new element is to be inserted
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    // ! Assign p->next to the next member of the ptr structure using ptr-> next = p->next, and the given data to its data member.

    p->next = ptr;
    // ? Break the connection between p and p->next by assigning p->next the new pointer. That is, p->next = ptr.

}

void insertAtEnd(In* head, int data)
{
    In* ptr = (In*)malloc(sizeof(In));
    ptr->data = data;
    In* p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    //* Break the connection between p and NULL by assigning p->next the new pointer. That is, p->next = ptr.
    ptr->next = NULL;
}

void insertAfterNode(In* head, int data, In* prevNode)
{
    In* ptr = (In*)malloc(sizeof(In));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

int main(){
    system("cls");
    // printf("Hello world\n");
    In* head;
    In* second;
    In* third;
    In* fourth;
    In* fifth;

    head = (In*)malloc(sizeof(In));
    second = (In*)malloc(sizeof(In));
    third = (In*)malloc(sizeof(In));
    fourth = (In*)malloc(sizeof(In));
    fifth = (In*)malloc(sizeof(In));

    head->data = 8;
    head->next = second;

    second->data = 19;
    second->next = third;

    third->data = 202;
    third->next = fourth;

    fourth->data = 1029;
    fourth->next = fifth;

    fifth->data = 2039;
    fifth->next = NULL;

    printf("Printing all the elements of the linked list!!\n");
    traverse(head);

    head = insertAtFirst(head, 109);
    printf("New element is inserted at first position!!\n");
    traverse(head);

    insertAtPosition(head, 29, 3);
    printf("New element is inserted in between two elements!!\n");
    traverse(head);

    insertAtEnd(head, 599);
    printf("New element is inserted at end!!\n");
    traverse(head);

    insertAfterNode(head, 10359, third);
    printf("New element is inserted after a node!!\n");
    traverse(head);

    return 0;
}


