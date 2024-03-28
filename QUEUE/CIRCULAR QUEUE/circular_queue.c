#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct queue
{
    int f;
    int r; 
    int size;
    int* arr;
}Queue; 

int isFull(Queue* q)
{
    if ((q->r+1)%(q->size) == q->f)
    {
        // printf("Queue is Full\n\n");
        return 1;
    }
    else return 0;
}

int isEmpty(Queue* q)
{
    if (q->f == q->r)
    {
        // printf("Queue is Empty\n\n");
        return 1;
    }
    else return 0;
}

void enqueue(int val, Queue* q)
{
    if(isFull(q))
    {
        printf("Queue Overflow! Cant add new elements to the array\n\n");
    }
    else
    {
        q->r = (q->r+1)%(q->size);
        q->arr[q->r] = val;
        printf("Enqueuied Element: %d\n", val);
    }
    
}

int dequeue(Queue* q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
    }
    else{
        q->f = (q->f+1)%(q->size);
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    system("cls");
    
    Queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) calloc(q.size, sizeof(int));

    enqueue(12, &q);
    enqueue(15, &q);
    enqueue(20, &q);
    
    for (int i = 0; i < q.size; i++)
    {
        printf("%d  ", q.arr[i]);
    }
    printf("\n\n");
    
    // printf("Dequeuing Element: %d\n", dequeue(&q));
    // printf("Dequeuing Element: %d\n", dequeue(&q));
    for (int i = 0; i < q.size ; i++)
    {
        printf("Dequeuing Element: %d\n", dequeue(&q));
        
    }
    
    enqueue(46, &q);
    enqueue(46, &q);
    enqueue(46, &q);
    
    
    
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    

    if (isFull(&q))
    {
        printf("Queue is Full\n");
    }
    
    
    
    return 0;
}