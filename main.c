#include "graph.h"
#include "attack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double robustness(node_t* seq[], size_t n, size_t N);

const char* filename;
int t;

size_t (*attack) (graph_t*, node_t* seq[]);


int parse_arg(int argc, char* argv[]) {
    int i;
    for (i=1; i!=argc; ++i) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'h': 
                    attack = high_degree_adaptive; break;
                case 'r': 
                    attack = random_attack; break;
                case 't': 
                    t = 1; break;
                default:
                    return 1;
            }
        } else if (filename == NULL) {
            filename = argv[i];
        } else return 1;
    }
    return filename == NULL;
}

int usage(char* argv0) {
    fprintf(stderr, "usage: %s [-h|-r] [-t] <filename>\n", argv0);
    fprintf(stderr,
            "\t<filename>:\tfilename of network, csv format.\n"
            "\t-h:\t\tuse High Degree Adaptive Attack (HDA). \n"
            "\t-r:\t\tuse random attack (HDA).\n"
            "\t-t:\t\tshow elapsed time of robustness calculation.\n"
            );
    return 1;
}

int main(int argc, char* argv[]) {
    if (parse_arg(argc, argv)) return usage(argv[0]);
    graph_t* graph = graph_read_csv(filename);
    node_t** seq = (node_t**) malloc(graph->n * sizeof(node_t*));
    size_t n = attack(graph, seq);
    time_t tic = clock();
    double R = robustness(seq, n, graph->n);
    time_t toc = clock();
    printf("%lf\n", R);
    if (t) printf("%lf\n",(double)(toc - tic) / CLOCKS_PER_SEC * 1000);
    return 0;
}
