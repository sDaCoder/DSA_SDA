#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue* next;  
}Q;

int isEmpty(Q** f)
{
    if (*f == NULL)
    {
        return 1;
    }
    else return 0;
}

int isFull(Q** f)
{
    Q* n = (Q*) malloc(sizeof(Q));
    if (n == NULL)
    {
        return 1;
    }
    else return 0;
}

void enq(Q** f, Q** r, int val)
{
    Q* n = (Q*) malloc(sizeof(Q));
    if (isFull(f))
    {
        printf("Queue Overflow\n\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;

        if (*f == NULL && *r==NULL)
        {
            *f = *r = n;
        }
        
        else
        {
            (*r)->next = n;
            *r = n;  // ! Last Node becomes the rear pointer 
        }
        // printf("Enqueuing Element: %d\n", val);
    }
}

int elementCount(Q** f)
{
    int count = 0;
    Q* ptr = *f;
    
    while ((ptr) != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    // free(ptr);
    return count;
}

int deq(Q** f)
{
    int val = -1;
    Q* ptr = *f;
    if (isEmpty(f))
    {
        printf("Queue Undeflow!\n\n");
    }
    else
    {
        *f = (*f)->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

void traverse(Q** f)
{
    Q* ptr = *f;
    printf("The Elements of the Linked List are: \n");
    while (ptr != NULL)
    {
        printf("%d  ", (ptr)->data);
        ptr = (ptr)->next;
    }
    printf("\n");
    free(ptr);
}

// ! 👇🏻👇🏻👇🏻 Dequeuing Elements Using Recursion
void deqAll(Q** f)
{
    if (isEmpty(f))
    {
        return;
    }
    printf("%d  ", deq(f));
    deqAll(f);
}

void main(){
    system("cls");

    Q* f = NULL;
    Q* r = NULL;

    
    enq(&f, &r, 10);
    enq(&f, &r, 20);
    enq(&f, &r, 30);
    enq(&f, &r, 40);
    enq(&f, &r, 50);
    enq(&f, &r, 60);
    traverse(&f);
    printf("\n");

    
    int element = elementCount(&f);
    printf("The total elements of the Queue is %d\n", elementCount(&f));
    
    printf("Dequeuing Elements: \n");

    // while (!isEmpty(&f))
    // {
    //     printf("%d  ", deq(&f));
    // }

    // do
    // {
    //     printf("%d  ", deq(&f));
    // } while (!isEmpty(&f));

    for (int i = 0; isEmpty(&f)!=1 ; i++)
    {
        printf("%d  ", deq(&f));
    }
    
    // deqAll(&f);
    printf("\n");

    printf("The total elements of the Queue is %d\n", elementCount(&f));
    printf("\n");
    

    if (isEmpty(&f)) printf("Queue is Empty\n\n");
    else printf("Queue is not Empty\n\n");
    
}