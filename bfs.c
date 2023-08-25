#include "_graph.h"
#include "_queue.h"
bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];
// typedef enum{
//     disc,
//     undisc,
//     procd
// } stat;
void init_search(graph *g){
    int i;
    for(i=0;i<=g->nvertices;i++){
        processed[i]=0;
        discovered[i]=0;
        parent[i]=-1;
    }
}
void bfs(graph *g,int st){
        queue q; // queue of vertex to visit
        int v; //curr. vertex
        int y; //successor vertex
        edge *p; //temp pointer
        init_queue(&q);
        enqueue(&q,st);
        discovered[st]=true;
        while(!empty_queue(&q)){
            v=dequeue(&q);
            process_vertex_early(v);
            processed[v]=true;
            p=g->edges[v];
            while(p!=NULL){
                y=p->y;
                if(!processed[y] || g->directed){
                    process_edge(v,y);
                }
                if(!discovered[y]){
                    enqueue(&q,y);
                    discovered[y]=true;
                    parent[y]=v;
                }
                p=p->next;
            }
            process_vertex_late(v);
        }
}