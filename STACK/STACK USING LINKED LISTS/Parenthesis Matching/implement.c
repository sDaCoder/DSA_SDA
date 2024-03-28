#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    char data;
    struct stack * next;
}stack;

int isEmpty(stack ** top)
{
    if (*top == NULL)
    {
        return 1; //! Stack is Empty
    }
    else return 0;
}

int isFull(stack ** top)
{
    stack * p = (stack *) malloc(sizeof(stack));
    //! If you cant dynamically allocate any memory, then the stack is full
    if (p==NULL)
    {
        return 1;
    }
    else return 0;
}
 
stack * push(stack ** top, char data)
{
    if (isFull(top))
    {
        printf("Stack Overflow! Cannot add %c to the array\n\n", data);
        // return 0;
    }
    stack * ptr = (stack *) malloc(sizeof(stack));
    ptr->data = data;
    ptr->next = *top;
    *top = ptr;
    return *top;
}

char pop(stack ** top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow! Cant pop any element from the stack\n\n");
    }
    stack * s = *top;
    *top = (*top)->next;
    char x = s->data;
    free(s);
    // printf("%c is popped from the stack\n\n", x);
    return x;
}

char peek(stack ** top, int pos)
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

char stackTop(stack ** top)
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

char stackBottom(stack ** top)
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

void traverse(stack ** top)
{
    printf("The stack using the linked list looks like: \n");
    while (*top != NULL)
    {
        printf("%c  ", (*top)->data);
        *top = (*top)->next;
    }
    printf("\n\n");
}

int parenMatch(char * exp)
{
    stack * top = NULL;
    for (int i = 0; exp[i]!='\0' ; i++)
    {
        if (exp[i] == '(')
        {
            push(&top, exp[i]);
        }
        else if(exp[i] == ')')
        {
            if (isEmpty(&top))
            {
                return 0;
            }
            pop(&top);
        } //End of else if()
    } //End of for() loop

    if(isEmpty(&top))
    {
        return 1;
    }
    else{
        return 0;
    }
}

void main()
{
    system("cls");

    char exp[1000] = "(10*(10+20*(67/5(45^7))))+2020(0)";
    // char exp[1000];
    // printf("Enter the expression please: ");
    // gets(exp);
    
    if(parenMatch(exp))
    {
        printf("Parenthesis Balanced\n");
    }
    else
    {
        printf("Parenthesis Unbalanced\n");
    }
}