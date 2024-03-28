#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack * next;
}stack;

int isEmpty(stack * top)
{
    if (top == NULL)
    {
        return 1; //! Stack is Empty
    }
    else return 0;
}

int isFull(stack * top)
{
    stack * p = (stack *) malloc(sizeof(stack));
    //! If you cant dynamically allocate any memory, then the stack is full
    if (p==NULL)
    {
        return 1;
    }
    else return 0;
}
 
stack * push(stack ** top, int data)
{
    if (isFull(*top))
    {
        printf("Stack Overflow! Cannot add %d to the array\n\n", data);
    }
    stack * ptr = (stack *) malloc(sizeof(stack));
    ptr->data = data;
    ptr->next = *top;
    *top = ptr;
    return *top;
}

int pop(stack ** top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow! Cant pop any element from the stack\n\n");
    }
    stack * s = *top;
    *top = (*top)->next;
    int x = s->data;
    free(s);
    printf("%d is popped from the stack\n\n", x);
    return x;
}

void traverse(stack * top)
{
    printf("The stack using the linked lists looks like: \n");
    while (top != NULL)
    {
        printf("%d  ", top->data);
        top = top->next;
    }
    printf("\n\n");
}

int main(){
    system("cls");
    stack * top = NULL;
    top = push(&top, 3);
    top = push(&top, 6);
    top = push(&top, 9);
    top = push(&top, 12);
    top = push(&top, 15);
    top = push(&top, 18);
    top = push(&top, 21);

    traverse(top);
    pop(&top);
    traverse(top);
    return 0;
}