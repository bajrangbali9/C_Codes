#include "_bfs.h"
typedef enum colour{
    U,W,B
}colour;
colour c[MAXV+1];
bool bipartate;
void twocolour(graph *g){
    int i;
    for(int i=0;i<=(g->nvertices);i++){
        c[i]=U;
    }
    bipartate=true;
    init_search(g);
    //TO BE CONTINUED......

}