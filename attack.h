#ifndef JR4ER_FAST_R_ATTACK_H
#define JR4ER_FAST_R_ATTACK_H

#include "graph.h"

size_t high_degree_adaptive(graph_t* g, node_t* seq[]);
size_t random_attack(graph_t* g, node_t* seq[]);

#endif
