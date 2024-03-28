#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct que
{
    int size;
    int f;  // ! Forward index
    int r;  // ! Rear index 
    int * arr;
}que;

int isFull(que* q)
{
    if (q->r == q->size-1)
    {
        printf("The Queue is Full");
        return 1;
    }
    else return 0;
}

int isEmpty(que* q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else return 0;
}

void enqR(int val, que* q)
{
    if (isFull(q))
    {
        printf("Queue Overflow!\n");
    }
    q->r = (q->r)+1;
    q->arr[q->r] = val;
    // printf("Enqueuing the element: %d\n", val);

}

void enqF(int val, que* q)
{
    if (isFull(q))
    {
        printf("Can't Add %d to the queue\n", val);
    }
    q->arr[q->f] = val;
    q->f--;
    // printf("Enqueuing Element: %d\n", val);
}

int deqF(que* q)
{
    int a = 0;
    if (isEmpty(q))
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        (q->f)++;
        a = q->arr[q->f];
    }
    
    return a;
}


void main(){
    system("cls");

    que q;
    q.f = q.r = -1;
    q.size = 100;
    q.arr = (int*) calloc(q.size, sizeof(int));
    
    
    enqR(20, &q);
    enqR(15, &q);
    enqR(10, &q);
    enqR(16, &q);
    enqR(37, &q);
    enqF(37, &q);

    traverse(&q);

    printf("Dequeuing Elements: \n");
    for (int i = 0; isEmpty(&q)!=1 ; i++)
    {
        printf("%d  ", deqF(&q));
    }
    printf("\n");
    printf("\n");
    
    if (isEmpty(&q)) printf("The Queue is Empty\n");
    else printf("The Queue is not Empty");
}