#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    int size;
    int * arr;
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
        // printf("The value %d is pushed into the stack\n\n", val);
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

int peek(int i, stack * ptr)
{
    int ind = (ptr->top - i + 1);
    if (ind < 0)
    {
        printf("Invalid Input! cant print the value at the position %d\n\n", i);
        return 0;
    }
    // printf("The value at the position %d is %d\n\n", i, ptr->arr[ind]);
    return  ptr->arr[ind];
}

void traverse(stack * ptr)
{
    printf("The elements of the stack from the top are: \n");
    for (int i = 0; i <= ptr->top; i++)
    {
        /* code */
        printf("%d  ", peek(i+1, ptr));
    }
    printf("\n\n");
}


int main(){
    stack * s = (stack *) malloc(sizeof(stack));
    s->top = -1;
    s->size = 10;
    s->arr = (int *) malloc(sizeof(int) * s->size);

    system("cls");
    pop(s);
    push(2, s);
    push(4, s);
    push(6, s);
    push(8, s);
    push(10, s);
    push(12, s);
    push(16, s);
    push(18, s);
    push(20, s);
    pop(s);
    // printf("%d\n", s->arr[(s->top)+1]);
    pop(s);
    // peek(1, s);
    traverse(s);


    return 0;
}