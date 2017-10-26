#include "graph.h"

static
node_t* find_set(node_t* u) {
    while (u->root->root != u->root)  u = u->root = u->root->root;
    return u->root;
}


static inline
size_t union_set(node_t* u, node_t* w) {
    node_t* u_root = find_set(u);
    node_t* w_root = find_set(w);
    if (u_root == w_root) return u_root->size;
    if (u_root->rank < w_root->rank) {
        u_root->root = w_root;
        return w_root->size += u_root->size;
    }
    if (u_root->rank == w_root->rank) u_root->rank++;
    w_root->root = u_root;
    return u_root->size += w_root->size;

}

double robustness(node_t* seq[], size_t n, size_t N) {
    node_t *u, **nb;
    size_t i;
    unsigned csba;
    size_t R = N - n;
    size_t max_csba = 0;
    while (n--) {
        u = seq[n];
        csba = u->size = 1;
        nb = u->neighbors;
        i = u->n;
        while (i--) if (nb[i]->size) {
            csba = union_set(u, nb[i]);
        }
        if (csba > max_csba) max_csba = csba;
        R += max_csba;
    }
    return (double) (R-max_csba) /  N / N;
}
