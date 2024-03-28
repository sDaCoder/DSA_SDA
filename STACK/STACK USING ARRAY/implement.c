#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}stack;

int isEmpty(stack * ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(stack * ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1; //! Condition is true
    }
    else{
        return 0;
    }
}

void main()
{
    system("cls");
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    stack *s = (stack *) malloc(sizeof(stack));
    s->size = 4;
    s->top= -1;
    s->arr= (int *) malloc(s->size * sizeof(int));

    // *Pushing the data manually
    s->arr[0] = 0;
    s->top++;
    
    s->arr[1] = 10;
    s->top++;
    
    s->arr[2] = 20;
    s->top++;

    s->arr[3] = 30;
    s->top++;
    
    //! Check if stack is empty
    if(isEmpty(s) == 1){
        printf("The stack is Empty\n");
    }
    else{
        printf("The stack is not Empty\n");
    }


    //! Check if the stack is full 
    if(isFull(s))
    {
        printf("The stack is Full\n");
    }
    else
    {
        printf("The stack is not Full\n");

    }

}