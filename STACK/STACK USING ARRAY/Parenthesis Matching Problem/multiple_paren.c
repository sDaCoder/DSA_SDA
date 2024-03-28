#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int match(char a, char b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    if (a=='{' && b=='}')
    {
        return 1;
    }
    if (a=='[' && b==']')
    {
        return 1;
    }
    return 0;
}

int parenMatch(char * exp)
{
    struct stack * sp = (stack *) malloc(sizeof(stack));
    sp->size = strlen(exp)+100;
    sp->top = -1;
    sp->arr = (char *) calloc(sp->size, sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i]!= '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(sp, exp[i]);
        } 
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (isEmpty(sp))
            {
                return 0; // !Condition is False, Parenthesis unmatched
            }
            else{
                popped_ch = pop(sp);
                if (!match(popped_ch, exp[i]))
                {
                    return 0; // !Condition is False, Parenthesis unmatched
                }
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else return 0;
}


void main()
{
    system("cls");
    // stack * s = (stack *) malloc(sizeof(stack));
    // s->size = 80;
    // s->top = -1;
    // s->arr = (char *) calloc(s->size, sizeof(char));

    // char * exp = "(8)*(9/7(100))367";
    // ! 👆🏻👆🏻👆🏻 char * exp does not work when the input is provided in the terminal
    
    char exp[1000];
    printf("Enter the expression please: ");
    gets(exp);
    // printf("%d\n", strlen(exp));

    if(parenMatch(exp)){
        printf("Parenthesis is Balanced\n");
    }
    else{
        printf("Parenthesis is Unbalanced\n");
    }
}