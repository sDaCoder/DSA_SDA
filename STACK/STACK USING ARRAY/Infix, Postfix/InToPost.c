#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
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

void push(stack * ptr, char val)
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

char pop(stack * s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow, can't pop any element from the stack\n\n");
        return 0;
    }
    char val = s->arr[s->top];
    free(&(s->arr[s->top]));
    s->top--;
    // printf("The value %d is popped from the stack\n\n", val);
    return val;
}

char stackTop(stack * s)
{
    return s->arr[s->top];
}

int isOperator(char ch)
{
    if (ch=='*' || ch=='/' || ch=='+' || ch=='-')
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

char* infixToPostfix(char* infix){

    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 

    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

void main()
{
    system("cls");

    // char exp[] = "a-b*d+c";
    // ! 👆🏻👆🏻👆🏻 char * exp does not work when the input is provided in the terminal
    
    char exp[1000];
    printf("Enter the expression please: ");
    gets(exp);
    printf("The postfix expression is: %s\n", infixToPostfix(exp));

}