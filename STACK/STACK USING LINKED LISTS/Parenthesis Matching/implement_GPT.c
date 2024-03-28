#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the linked list
typedef struct node {
    char data;
    struct node * next;
} node;

// Define a stack structure using a linked list
typedef struct stack {
    node * top;
} stack;

// Create a new node with given data and return its pointer
node * createNode(char data) {
    node * newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize a stack and return its pointer
stack * createStack() {
    stack * newStack = (stack *)malloc(sizeof(stack));
    newStack->top = NULL;
    return newStack;
}

// Check if a stack is empty or not
int isEmpty(stack * s) {
    return s->top == NULL;
}

// Push a new node with given data onto the stack
void push(char data, stack * s) {
    node * newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

// Pop the top node from the stack and return its data
char pop(stack * s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    }
    node * temp = s->top;
    char data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}

// Return the data of the top node of the stack without removing it
char peek(stack * s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->top->data;
}

// Free the memory allocated for the stack
void freeStack(stack * s) {
    node * temp = s->top;
    while (temp != NULL) {
        node * next = temp->next;
        free(temp);
        temp = next;
    }
    free(s);
}

// Check if the parentheses in an expression are balanced or not
int parenMatch(char * exp) {
    // Create a stack to store the opening parentheses
    stack * s = createStack();
    
    // Store the length of the expression
    int len = strlen(exp);

    // Loop through the expression
    for (int i = 0; i < len; i++) {
        // If an opening parenthesis is encountered, push it onto the stack
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            push(exp[i], s);
        }
        // If a closing parenthesis is encountered, pop the top element from the stack and check if it matches
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            // If the stack is empty, or the popped element does not match, return 0 (false)
            if (isEmpty(s) || peek(s) != exp[i] - 1 && peek(s) != exp[i] - 2) {
                freeStack(s);
                return 0;
            }
            // If the popped element matches, continue scanning the expression
            else {
                pop(s);
            }
        }
    }
    
    // At the end, if the stack is empty, return 1 (true), otherwise return 0 (false)
    int result = isEmpty(s);
    freeStack(s);
    return result;
}

// Test the algorithm with some examples
int main() {
    
    char * exp1 = "[(a+b)*(c-d)]";
    char * exp2 = "[(a+b]*(c-d)]";
    
    printf("%s is %s\n", exp1, parenMatch(exp1) ? "balanced" : "not balanced");
    
    printf("%s is %s\n", exp2, parenMatch(exp2) ? "balanced" : "not balanced");
    
}
