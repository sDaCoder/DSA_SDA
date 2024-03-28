#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack * ptr)
{
    for(int i=0; i<(ptr->size); i++)
    {
        printf("Enter the value of the %d th element of the stack: ", i+1);
        scanf("%d", &(ptr->arr[i]));
        ptr->top++;
    }
}

void traverse(struct stack * ptr)
{
    printf("The elements of the stack are: \n");
    for (int i = 0; i < ptr->size; i++)
    {
        printf("%d  ", ptr->arr[i]);
    }
    
}

int main()
{
    system("cls");
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
 
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    

    // * Pushing the data using a function
    push(s);

    //! Check if stack is empty
    if(isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }
    
    //! Check whether stack is full
    if(isFull(s)) 
    {
        printf("The stack is Full\n");
    }
    else
    {
        printf("The stack is not Full\n");
    }

    traverse(s);
    
    return 0;
}
