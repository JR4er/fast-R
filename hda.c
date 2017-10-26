#include "graph.h"
#include <memory.h>


static inline
void set(node_t** ref, node_t* node) {
    *ref = node;
    if (node) node->ref = ref;
}

static inline
void push(node_t** ref, node_t* node) {
    set(&node->next, *ref);
    *ref = node;
    node->ref = ref;
}

static inline
node_t* pop(node_t** ref) {
    node_t* node = *ref;
    if (node) set(ref, node->next);
    return node;
}

size_t high_degree_adaptive(graph_t* g, node_t* seq[]) {
    size_t n = g->n;
    memset(seq, 0, n * sizeof(*seq));
    size_t i = n;
    node_t *u = g->v;
    
    while (i--) {
        push(&seq[u->k], u);
        u++;
    }

    node_t *list = NULL;
    node_t **ref = &list;
    node_t **nb, *v;

    while (--n) while (( u=pop(&seq[n]) )){
        nb = u->neighbors;
        i = u->n;
        while (i--) if ((v=nb[i])->size){
            pop(v->ref);
            push(&seq[--v->k], v);
        }

        u->size = 0;
        *ref = u;
        ref = &u->next;
    }
    *ref = NULL;
    while (list) {
        seq[n++] = list;
        list = list->next;
    }
    return n;
}
