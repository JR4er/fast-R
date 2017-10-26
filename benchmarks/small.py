#!/usr/local/bin/python3
import random
import networkx as nx

random.seed(0)

n = [100, 500, 1000]
k = 5

for i in n:
    nx.write_edgelist(nx.random_graphs.barabasi_albert_graph(i,k), "BA_{0}_{1}.csv".format(i,k), delimiter=",", data = False)
    nx.write_edgelist(nx.random_graphs.erdos_renyi_graph(i,2.0*k/i), "ER_{0}_{1}.csv".format(i,k), delimiter=",", data = False) 
    nx.write_edgelist(nx.random_graphs.watts_strogatz_graph(i,2*k,0.1), "WS_{0}_{1}.csv".format(i,k), delimiter=",", data = False)
    nx.write_edgelist(nx.random_graphs.watts_strogatz_graph(i,2*k,0.1), "WS_{0}_{1}.csv".format(i,k), delimiter=",", data = False)
    nx.write_edgelist(nx.classic.star_graph(i), "S_{0}.csv".format(i), delimiter=",", data = False)
    nx.write_edgelist(nx.classic.complete_graph(i), "C_{0}.csv".format(i), delimiter=",", data = False)
