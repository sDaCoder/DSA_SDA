#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

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

int isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    else return 0;
}

int precedence(char ch)
{
    if (ch=='*' || ch=='/')
    {
        return 3;
    }
    else if (ch=='+' || ch=='-')
    {
        return 2;
    }
    else return 0;
}

char * infixToPostfix(char * infix)
{
    stack * s = NULL;
    char * post = (char*) calloc(strlen(infix)+1, sizeof(char));
    int i = 0; // ! infix scanner
    int j = 0; // ! Postfix Filling

    while (infix[i]!='\0')
    {
        if (!isOperator(infix[i]))
        {
            post[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(&s)))
            {
                push(&s, infix[i]);
                i++;
            }
            else
            {
                post[j] = pop(&s);
                j++;
            }
        }
    }

    while (!isEmpty(&s))
    {
        post[j] = pop(&s);
        j++;
    }
    
    post[j] = '\0';
    return post;
            
    
}

void main()
{
    system("cls");

    char exp[1000] = "x-y/z-k*d";
    puts(exp);

    // char exp[1000];
    // printf("Enter the expression please: ");
    // gets(exp);

    printf("The Postfix of the expression is: %s\n", infixToPostfix(exp));
    
    // if(parenMatch(exp))
    // {
    //     printf("Parenthesis Balanced\n");
    // }
    // else
    // {
    //     printf("Parenthesis Unbalanced\n");
    // }
}