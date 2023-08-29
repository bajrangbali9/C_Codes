#include "_queue.h"
#include "_graph.h"
bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];
void init_search(graph *g){
    int i;
    for(i=0;i<=g->nvertices;i++){
        processed[i]=0;
        discovered[i]=0;
        parent[i]=-1;
    }
}

void process_vertex_early(int v){
    printf("%d",v);
}
void process_vertex_late(int v){

}
void process_edge(int x,int y){
    
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


void connected_components(graph *g){
    int c; // component number
    int i;
    init_search(g);
    c=0;
    for(i=1;i<=g->nvertices;i++){
        if(!discovered[i]){
            c=c+1;
            printf("Component %d",c);
            bfs(g,i);
            printf("/n");
        }
    }
}