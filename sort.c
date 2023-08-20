#include <stdio.h>
#include <stdlib.h>
#define PQ_SIZE 10
// qsort(int *a,n,sizeof(int),intcompare);
int intcompare(int *i, int *j)
{
    if (*i > *j)
        return (1);
    if (*i < *j)
        return (-1);
    return (0);
}
typedef struct
{
    int q[PQ_SIZE + 1];
    int n;
} priority_queue;
void pq_swap(priority_queue *q, int i, int j)
{
    int tmp = q->q[i];
    q->q[i] = q->q[j];
    q->q[j] = tmp;
}
int pq_parent(int n)
{
    if (n == 1)
    {
        return (-1);
    }
    return ((int)n / 2);
}
int pq_youngc(int n)
{
    return (2 * n);
}
pq_oldc(int n)
{
    return (2 * n + 1);
}
void bubble_up(priority_queue *q, int p)
{
    if (pq_parent(p) == -1)
    {
        return;
    }
    if (q->q[pq_parent(p)] > q->q[p])
    {
        pq_swap(q, p, pq_parent(p));
        bubble_up(q, pq_parent(p));
    }
}
void bubble_down(priority_queue *q, int p)
{
    int c;         // child index
    int i;         // counter
    int min_index; // index of lightest child
    c = pq_youngc(p);
    min_index = p;
    for (i = 0; i <= 1; i++)
    {
        if (c + i <= q->n)
        {
            if (q->q[min_index] > q->q[c + i])
            {
                min_index = c + i;
            }
        }
    }
    if (min_index != p)
    {
        pq_swap(q, p, min_index);
        bubble_down(q, min_index);
    }
}
void pq_insert(priority_queue *q, int x)
{
    if (q->n >= PQ_SIZE)
    {
        printf("Warning: priority queue overflow");
    }
    else
    {
        q->n = (q->n) + 1;
        q->q[q->n] = x;
        bubble_up(q, q->n);
    }
}
void pq_init(priority_queue *q)
{
    q->n = 0;
}
void make_heap(priority_queue *q, int *s, int n)
{
    int i;
    pq_init(q);
    for (i = 0; i < n; i++)
    {
        pq_insert(q, s[i]);
    }
}
int extract_min(priority_queue *q)
{
    int min = -1;
    if (q->n <= 0)
    {
        printf("Warning:empty priority queue");
    }
    else
    {
        min = q->q[1];
        q->q[1] = q->q[q->n];
        q->n = (q->n) - 1;
        bubble_down(q, 1);
    }
    return (min);
}
void heapsort(int *s, int n)
{
    int i;
    priority_queue q;
    make_heap(&q, s, n);
    for (i = 0; i < n; i++)
    {
        s[i] = extract_min(&q);
    }
}

void make_heap_fast(priority_queue *q, int *s, int n)
{
    int i;
    q->n = n;
    for (i = 0; i < n; i++)
    {
        q->q[i + 1] = s[i];
    }
    for (i = q->n / 2; i >= 1; i++)
    {
        bubble_down(q, i);
    }
}

int heap_compare(priority_queue *q, int i, int count, int x)
{
    if (count <= 0 || i > q->n)
    {
        return (count);
    }
    if (q->q[i] < x)
    {
        count = heap_compare(q, pq_youngc(q), count - 1, x);
        count = heap_compare(q, pq_oldc(q), count, x);
    }
    return (count);
}

void merge_sort(int *s,int low)