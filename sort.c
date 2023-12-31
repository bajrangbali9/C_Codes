#include <stdio.h>
#include <stdlib.h>
#include "_queue.h"
#define PQ_SIZE 100
// qsort(int *a,n,sizeof(int),intcompare);
void swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}
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

void merge(int *s, int low, int mid, int high)
{
    int i;
    queue bf1, bf2;
    init_queue(&bf1);
    init_queue(&bf2);
    for (i = low; i <= mid; i++)
        enqueue(&bf1, s[i]);
    for (i = mid + 1; i <= high; i++)
        enqueue(&bf2, s[i]);
    i = low;
    while (!(empty_queue(&bf1) || empty_queue(&bf2)))
    {
        if (headq(&bf1) <= headq(&bf2))
        {
            s[i++] = dequeue(&bf1);
        }
        else
        {
            s[i++] = dequeue(&bf2);
        }
    }
    while (!empty_queue(&bf1))
    {
        s[i++] = dequeue(&bf1);
    }
    while (!empty_queue(&bf2))
    {
        s[i++] = dequeue(&bf2);
    }
}

void merge_sort(int *s, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(s, low, mid);
        merge_sort(s, mid + 1, high);

        merge(s, low, mid, high);
    }
}

int partition(int *s, int l, int h)
{
    int i;
    int p;
    int fst_ht;
    p = h;
    fst_ht = l;
    for (i = l; i < h; i++)
    {
        if (s[i] < s[p])
        {
            swap(s + i, s + fst_ht);
        }
    }
    swap(s + p, s + fst_ht);
    return (fst_ht);
}

void quicksort(int *s, int l, int h)
{
    int p;
    if (l < h)
    {
        p = partition(s, l, h);
        quicksort(s, l, p - 1);
        quicksort(s, p + 1, h);
    }
}