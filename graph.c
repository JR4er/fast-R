#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

static inline
void init(node_t* v) {
    *v = (node_t){
        0,0,NULL,
        NULL, NULL,
        0,1, v
    };
}

graph_t* graph_read_csv(const char* filename) {
    FILE* csv = fopen(filename, "r");
    size_t n=0, m=0;
    unsigned a, b;
    while (fscanf(csv, "%u,%u", &a, &b) != EOF) {
        if (a >=n ) n = a+1;
        if (b >=n ) n = b+1;
        m++;
    }
    graph_t* g = (graph_t*) malloc(sizeof(graph_t) + n * sizeof(node_t));
    node_t* v = g->v;
    size_t i;
    for (i=0; i!=n; ++i) init(v+i);
    node_t** e = (node_t**) malloc(2*m*sizeof(node_t*));

    fseek(csv, 0, SEEK_SET);
    while (fscanf(csv, "%u,%u", &a, &b) != EOF) {
        v[a].n++;
        v[b].n++;
    }
    for (i=0; i!=n; ++i) {
        v[i].neighbors = e;
        e += v[i].n;
    }

    fseek(csv, 0, SEEK_SET);
    while (fscanf(csv, "%u,%u", &a, &b) != EOF) {
        v[a].neighbors[v[a].k++] = &v[b];
        v[b].neighbors[v[b].k++] = &v[a];
    }
    fclose(csv);
    g->m = m;
    g->n = n;
    return g;
}

void graph_free(graph_t* g) {
    free(g->v[0].neighbors);
    free(g);
}

static
void tidy(node_t* nb[], size_t n, size_t k) {
    if (n==k || k==0) return;
    node_t* x = nb[0];
    if (x->size) k--;
    size_t i = 0, j = k;
    while (1) {
        while (j<n && !nb[j]->size) j++;
        if (j==n) break;
        nb[i++] = nb[j];
        while (i<k && nb[i]->size) i++;
        if (i==k) break;
        nb[j++] = nb[i];
    }
    nb[k] = x;
}


void node_tidy_neighbor(node_t* n) {
    tidy(n->neighbors, n->n, n->k);
}
