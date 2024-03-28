#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct queue
{
    int size;
    int f;  // ! Forward index
    int r;  // ! Rear index 
    int * arr;
}queue;

int isFull(queue* q)
{
    if (q->r == q->size-1)
    {
        printf("The Queue is Full");
        return 1;
    }
    else return 0;
}

int isEmpty(queue* q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else return 0;
}

void enqueue(int val, queue* q)
{
    if (isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    q->r = (q->r)+1;
    q->arr[q->r] = val;
    printf("Enqueuing the element: %d\n", val);

}

int dequeue(queue* q)
{
    int a;
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
    }
    (q->f)++;
    a = q->arr[q->f];
    return a;
}

int main(){
    system("cls");
    queue q;
    q.f = q.r = -1;
    q.size = 100;
    q.arr = (int*) calloc(q.size, sizeof(int));
    
    
    enqueue(20, &q);
    enqueue(15, &q);
    enqueue(10, &q);
    enqueue(16, &q);
    enqueue(37, &q);
    enqueue(98, &q);
    enqueue(100, &q);
    enqueue(364, &q);
    enqueue(112, &q);

    for (int i = 0; isEmpty(&q)!=1 ; i++)
    {
        printf("Dequeuing the element: %d\n", dequeue(&q));
    }
    
    
    if (isEmpty(&q))
    {
        printf("The Queue is Empty\n");
    }
    else printf("The Queue is not Empty");
    return 0;
}