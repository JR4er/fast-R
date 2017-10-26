#include "graph.h"
#include <stdlib.h>

static inline
void heap_set(node_t* heap[], unsigned i, node_t* n) {
    (heap[i] = n)->rank = i;
}
static inline
void heap_swap(node_t* heap[], unsigned i, unsigned j) {
    node_t* tmp = heap[i];
    heap_set(heap, i, heap[j]);
    heap_set(heap, j, tmp);
}

static
void heap_maxify(node_t* heap[], size_t n, unsigned i) {
    unsigned r,l,max;
    while (1) {
        max = i;
        l = (i<<1) + 1;
        r = l + 1;
        if (l < n && heap[l]->size > heap[max]->size) max = l;
        if (r < n && heap[r]->size > heap[max]->size) max = r;
        if (max == i) return;
        heap_swap(heap, i, max);
        i = max;
    }
}

static
void heap_popup(node_t* heap[], unsigned i, node_t* n) {
    unsigned p;
    while (i && heap[p=(i-1)>>1]->size < n->size) {
        heap_set(heap, i, heap[p]);
        i = p;
    }
    heap_set(heap, i, n);
}

static inline 
void heap_push(node_t* heap[], size_t* n, node_t* node) {
    heap_popup(heap, (*n)++, node);
}

static inline
void heap_delete(node_t* heap[], size_t* n, node_t* node) {
    node_t* last = heap[--(*n)];
    if (last->size >  node->size) return heap_popup(heap, node->rank, last);
    heap_set(heap, node->rank, last);
    if (node->size > last->size) heap_maxify(heap, *n, node->rank);
}

static
void flood(node_t* seed, node_t* comm, node_t* queue[]) {
    size_t l = 0, h = 0;
    seed->root = comm;
    queue[h++] = seed;
    node_t *u, *v, **nb;;
    size_t i;
    while (l<h) {
        u = queue[l++];
        i = u->n;
        nb = u->neighbors;
        while (i--) if ((v=nb[i])->size) {
            if (v->root == comm) continue;
            v->root = comm;
            queue[h++] = v;
        }
    }
    comm->size = h;
}

static inline
node_t* new_seed(node_t* v, node_t* old) {
    if (v != old) return v;;
    size_t i = v->n;
    while (i--) if (v->neighbors[i]->size) return v->neighbors[i];
    return v;
}

double robustness(node_t* seq[], size_t n, size_t N) {
    node_t** heap = (node_t**) malloc(sizeof(node_t*) * N);
    node_t** queue = (node_t**) malloc(sizeof(node_t*) * N);

    size_t heap_size = 0;
    size_t i, j;

    size_t R = N - n - 1;
    for (i=0; i!=n; ++i) seq[i]->size = 1;
    
    for (i=0; i!=n; ++i) if (seq[i]->root == seq[i]) {
        flood(seq[i], seq[i], queue);
        heap_push(heap, &heap_size, seq[i]);
    }

    node_t *u, *v, *old, *new, **nb;
    for (i=0; i!=n; ++i) {
        u = seq[i];
        old = u->root;
        heap_delete(heap, &heap_size, old);
        nb = u->neighbors;
        j = u->n;
        u->size = 0;
        while (j--) if ((v=nb[j])->size){
            if (v->root != old) continue;
            new = new_seed(v, old);
            flood(v, new, queue);
            heap_push(heap, &heap_size, new);
        }
        R += heap[0]->size;
    }
    free(heap);
    free(queue);
    return (double) R / N / N;
}
