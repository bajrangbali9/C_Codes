#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;
typedef struct
{
    list *front;
    list *rear;
} queue;

void init_queue(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}
int empty_queue(queue *q)
{
    return (q->front == NULL);
}
void enqueue(queue *q, int x)
{
    list *new = (list *)malloc(sizeof(list));
    new->data = x;
    new->next = NULL;
    if (empty_queue(q))
    {
        q->front = new;
        q->rear = new;
    }
    else
    {
        q->rear->next = new;
        q->rear = new;
    }
}
int dequeue(queue *q)
{
    if (empty_queue(q))
    {
        printf("No elements in queue");
        // exit(EXIT_FAILURE);
        return (-1);
    }
    list *fnt = q->front;
    int x = q->front->data;
    q->front = fnt->next;
    free(fnt);
    return (x);
}

int headq(queue *q)
{
    if (empty_queue(q))
    {
        printf("no head found");
        return (-1);
    }
    return (q->front->data);
}

void clear_queue(queue *q)
{
    while (!empty_queue(q))
    {
        dequeue(q);
    }
}