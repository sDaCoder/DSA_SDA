#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
} Node;

void traverse(Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

Node* dele1(Node *head)
{
    Node * ptr = head;
    head = head->next;
    free(ptr);

    return(head);
}

void deleInBw(Node *head, int index)
{
    Node * p = head;
    Node * ptr = head->next;

    //* int i = 0; 
    //* while (i != index-1)
    //* {
    //*     p = p->next;    
    //*     i++;
    //* }
    
    //* int j = 0; 
    //* while (j != index)
    //* {
    //*     ptr = ptr->next;    
    //*     j++;
    //* }
    //* p->next = ptr->next;

    // TODO: aliter
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    free(ptr);

    traverse(head);

}

void deleEnd(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    traverse(head);
}

void deleVal(Node *head, int val)
{
    Node *p = head;
    Node *q = head->next;

    while (q->data != val && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == val)
    {
        p->next = q->next;
        free(q);
        traverse(head);
    }
    else
    {
        printf("%d is not available in the list\n\n", val);
    }
    
}

int main(){
    system("cls");
    // printf("Hello world\n");
    
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
    Node *fifth;
 
    //! Allocate memory for nodes in the linked list in Heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));
    fifth = (Node *)malloc(sizeof(Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = fifth;

    fifth->data = 1020;
    fifth->next = NULL;
 
    traverse(head);

    deleVal(head, 1937);

    deleVal(head, 66);

    deleEnd(head);
    
    deleVal(head, 1001);

    deleInBw(head, 2);

    head = dele1(head);
    traverse(head);
    

    return 0;
}