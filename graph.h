#ifndef JR4ER_FAST_R_GRAPH_H
#define JR4ER_FAST_R_GRAPH_H

#include <stddef.h>

typedef struct node {
    unsigned n; // number of total neighbors
    unsigned k; // number of current neighbors
    struct node** neighbors;

    /* fields for HDA bucket sort */
    struct node* next;
    struct node** ref;

    /* fields for R calculate */
    unsigned rank, size;
    struct node* root;
} node_t;

typedef struct {
    size_t n,m;
    node_t v[0];
} graph_t;

graph_t* graph_read_csv(const char* filename);
void     graph_free(graph_t* graph);

#endif
