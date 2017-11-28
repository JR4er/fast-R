#!/usr/local/bin/python3
import random
import networkx as nx

random.seed(0)

i = 10000

for k in range(1,101):
    print(k)
    nx.write_edgelist(nx.random_graphs.barabasi_albert_graph(i,k), "BA_{0}_{1}.csv".format(i,k), delimiter=",", data = False)
    nx.write_edgelist(nx.random_graphs.erdos_renyi_graph(i,2.0*k/i), "ER_{0}_{1}.csv".format(i,k), delimiter=",", data = False) 
    nx.write_edgelist(nx.random_graphs.watts_strogatz_graph(i,2*k,0.1), "WS_{0}_{1}.csv".format(i,k), delimiter=",", data = False)
