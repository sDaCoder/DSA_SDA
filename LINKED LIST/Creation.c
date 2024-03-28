
#include <stdio.h>
#include <stdlib.h>

// TODO: CREATING A LINKED LIST WITH THE STRUCT DATA STRUCTURE STORING THE FIRST DATA ELEMENT OF THE LINKED LIST AND A POINTER POINTING THE LINKED LIST 👇🏻
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
 
// TODO: TRAVERSING ALL THE ELEMENTS OF THE LINKED LIST 
void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
 
int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;
 
    //! Allocate memory for nodes in the linked list in Heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));
 
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
    fourth->next = NULL;
 
    linkedListTraversal(head);
    return 0;
}
