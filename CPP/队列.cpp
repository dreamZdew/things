#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 7
typedef char QElemType;
typedef int Status;
typedef struct
{
    char data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

char InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return 1;
}
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnQueue(SqQueue *Q, QElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return 0;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if (Q->front == Q->rear)
        return 0;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 0;
}
int main()
{
    SqQueue Q;
    InitQueue(&Q);
    char e;
    e = getchar();
    while (e != '#')
    {
        EnQueue(&Q, e);
        e = getchar();
    }
    if (QueueLength(Q) == MAXSIZE - 1)
        printf("full\n");
    else
        printf("not full\n");
    QElemType *k;
    while (QueueLength(Q) != 0)
    {
        DeQueue(&Q, k);
        printf("%c", *k);
    }
}
