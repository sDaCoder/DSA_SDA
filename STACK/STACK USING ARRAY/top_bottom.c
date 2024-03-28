#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
}stack;

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(stack * ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
 
void push(int val, stack * ptr)
{
    if(isFull(ptr) == 1)
    {
        printf("Stack Overflow! Can't add any elements to the stack\n\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("The value %d is pushed into the stack\n\n", val);
    }
}

int pop(stack * s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow, can't pop any element from the stack\n\n");
        return 0;
    }
    int val = s->arr[s->top];
    free(&(s->arr[s->top]));
    s->top--;
    printf("The value %d is popped from the stack\n\n", val);
    return val;
}

int stackTop(stack * ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(stack * ptr)
{
    return ptr->arr[0];
}

void main()
{
    system("cls");
    stack * s = (stack *) malloc(sizeof(stack));
    s->top = -1;
    s->size = 10;
    s->arr = (int *) calloc(s->size, sizeof(int));

    push(9, s);
    push(18, s);
    push(27, s);
    push(36, s);
    printf("The Bottom-most element of the stack is %d\n\n", stackBottom(s));
    printf("The topmost element of the stack now is %d\n\n", stackTop(s));
    pop(s);
    printf("The topmost element of the stack now is %d\n\n", stackTop(s));

}