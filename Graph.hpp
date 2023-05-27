#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector> //std::vector std::empty

//alias
using vec = std::vector<int>;

struct Edge {
    int to, cap, rev;
};

struct Graph {
    int V;
    std::vector<std::vector<Edge>> G;
    vec used, level;


    Graph(int n);
    void add_edge(int from, int to, int cap);
    bool bfs(int s, int t);
    int dfs(int v, int t, int f);
    int max_flow(int s, int t);
    bool has_isolated_vertex();
};

#endif //GRAPH_HPP
