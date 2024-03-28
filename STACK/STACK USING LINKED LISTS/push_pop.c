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
        return 1;
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
 
stack * push(stack * top, int data)
{
    if (isFull(top))
    {
        printf("Stack overflow! Can't add %d to the stack\n\n", data);
    }
    else
    {
        stack * ptr = (stack *) malloc(sizeof(stack));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
        return top;
    }
    
}

void traverse(stack * top)
{
    printf("The Stack looks like: \n");
    while(top != NULL)
    {
        printf("%d  ", top->data);
        top = top->next;
    }
    printf("\n\n");
}

int pop(stack ** top)
{
    if (isFull(*top))
    {
        printf("Stack Underflow! Cant pop any element from the stack\n\n");
        return 0;
    }
    else
    {
        stack * s = *top;
        *top = (*top)->next;
        int x = s->data;
        free(s);
        return x;
    }
    
}

int main(){
    system("cls");
    stack * top = NULL;
    top = push(top, 78);
    top = push(top, 88);
    top = push(top, 98);
    top = push(top, 108);
    top = push(top, 118);

    traverse(top);
    int element = pop(&(top));
    printf("The popped element is %d\n\n", element);
    traverse(top);
    return 0;
}