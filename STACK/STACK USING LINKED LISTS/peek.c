#include<stdio.h>
#include<stdlib.h>

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

int peek(stack ** top, int pos)
{
    stack * ptr = *top;
    for (int i = 0; (i < pos-1)  &&  (ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else return -1;
}

int stackTop(stack ** top)
{
    return (*top)->data;
}

int elementCount(stack ** top)
{
    stack * ptr = *top;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = (ptr)->next;
        count++;
    }
    return count;
}

int stackBottom(stack ** top)
{
    stack * ptr = *top;
    stack * prev = NULL;
    
    while (ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    
    return prev->data;
}


void main()
{
    system("cls");
    stack * top = NULL;
    top = push(&top, 3);
    top = push(&top, 6);
    top = push(&top, 9);
    top = push(&top, 12);
    top = push(&top, 15);
    top = push(&top, 18);
    top = push(&top, 21);
    top = push(&top, 24);
    top = push(&top, 27);
    top = push(&top, 30);
    top = push(&top, 33);
    top = push(&top, 36);
    top = push(&top, 39);
    top = push(&top, 42);
    top = push(&top, 45);
    top = push(&top, 48);
    top = push(&top, 51);
    pop(&top);

    printf("The Stack looks like this: \n");
    for (int i = 0; i < elementCount(&top); i++)
    {
        printf("%d  ", peek(&top, i+1));
    }
    printf("\n\n");
    
    printf("The topmost element of the stack is %d\n\n", stackTop(&top));
    printf("The Bottom-most element of the stack is %d\n\n", stackBottom(&top));

}