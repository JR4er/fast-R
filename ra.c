#include "graph.h"
#include <stdlib.h>

size_t random_attack(graph_t* graph, node_t* seq[]) {
    size_t n = graph->n;
    size_t m = graph->m;
    size_t i,j;
    node_t* u = graph->v;
    
    for (i=0; i!=n; ++i) seq[i] = u++; 

    i = 0;
    node_t** nb;
    while (m && i<n) {
        j = rand() % (n-i) + i;
        u = seq[i];
        if (i!=j) {
            u = seq[j]; seq[j] = seq[i]; seq[i] = u;
        } 
        nb = u->neighbors;
        j = u->n;
        while (j--) if (nb[j]->size) nb[j]->k--;
        u->size = 0;
        i++;
        m-=u->k;
    }
    return i;
}
