#include <algorithm> //std::fill, std::min
#include <climits> //INT_MAX
#include <queue> //std::queue
#include <vector> //std::vector std::empty

#include "Graph.hpp"
//alias
using vec=std::vector<int>;

Graph::Graph(int n) : V(n), G(n), used(n), level(n) {}

void Graph::add_edge(int from, int to, int cap) {
        G[from].push_back({ to, cap, (int)G[to].size() });
        G[to].push_back({ from, 0, (int)G[from].size() - 1 });
    }

bool Graph::bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        level[s] = 0;
        std::queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

int Graph::dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

int Graph::max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(used.begin(), used.end(), 0);
            int f;
            while ((f = dfs(s, t, INT_MAX)) > 0) {
                flow += f;
            }
        }
        return flow;
    }

bool Graph::has_isolated_vertex() {
    for (int i = 1; i < V - 1; i++) {
        if (G[i].empty()) {
            return true;
        }
    }
    return false;
}





