#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXV 100
typedef struct edge
{
    int y;             // adjency info
    int weight;        // edge weight
    struct edge *next; // next edge in list
} edge;
typedef struct graph
{
    edge *edges[MAXV + 1];
    int degree[MAXV + 1];
    int nvertices;
    int nedges;
    int directed;
} graph;
void init_graph(graph *g, bool directed)
{
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (i = 0; i < MAXV; i++)
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, bool directed)
{
    edge *p;
    p = (edge *)malloc(sizeof(edge));
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p; // insert at head
    g->degree[x]++;
    if (!directed)
    {
        insert_edge(g, y, x, true);
    }
    else
    {
        g->nedges++;
    }
}
void read_graph(graph *g, bool directed)
{
    int i;
    int m;
    int x, y;
    init_graph(g, directed);
    scanf("%d %d", &(g->nvertices), &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

void print_graph(graph *g)
{
    int i;
    edge *p;
    for (i = 1; i <= g->nvertices; i++)
    {
        printf("%d", i);
        p = g->edges[i];
        while (p != NULL)
        {
            printf("%d", p->y);
            p = p->next;
        }
        printf("\n");
    }
}

