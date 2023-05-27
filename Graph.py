import sys


class Edge:
    def __init__(self, to, cap, rev):
        self.to = to
        self.cap = cap
        self.rev = rev


class Graph:
    def __init__(self, n):
        self.V = n
        self.G = [[] for _ in range(n)]
        self.used = [0] * n
        self.level = [0] * n

    def add_edge(self, from_, to, cap):
        self.G[from_].append(Edge(to, cap, len(self.G[to])))
        self.G[to].append(Edge(from_, 0, len(self.G[from_]) - 1))

    def bfs(self, s, t):
        self.level = [-1] * self.V
        self.level[s] = 0
        q = [s]
        while q:
            v = q.pop(0)
            for e in self.G[v]:
                if e.cap > 0 and self.level[e.to] < 0:
                    self.level[e.to] = self.level[v] + 1
                    q.append(e.to)
        return self.level[t] >= 0

    def dfs(self, v, t, f):
        if v == t:
            return f
        self.used[v] = 1
        for e in self.G[v]:
            if not self.used[e.to] and e.cap > 0 and self.level[v] < self.level[e.to]:
                d = self.dfs(e.to, t, min(f, e.cap))
                if d > 0:
                    e.cap -= d
                    self.G[e.to][e.rev].cap += d
                    return d
        return 0

    def max_flow(self, s, t):
        flow = 0
        while self.bfs(s, t):
            self.used = [0] * self.V
            while True:
                f = self.dfs(s, t, sys.maxsize)
                if f == 0:
                    break
                flow += f
        return flow
    
    def has_isolated_vertex(self):
        for i in range(1, self.V - 1):
            if not self.G[i]:
                return True
        return False



def read_graph_from_file(filename):
    with open(filename, 'r') as file:
        V, m = map(int, file.readline().split())
        graph = Graph(V)
        for _ in range(m):
            u, v = map(int, file.readline().split())
            graph.add_edge(u - 1, v - 1, 1)
            graph.add_edge(v - 1, u - 1, 1)
    return graph


def write_result_to_file(vertex_connectivity, filename):
    with open(filename, 'a') as file:
        file.write(f"\nVertex connectivity is {vertex_connectivity}\n")



def read_graph_from_file(filename):
    with open(filename, 'r') as file:
        V, E = map(int, file.readline().split())
        graph = Graph(V)
        for _ in range(E):
            u, v = map(int, file.readline().split())
            graph.add_edge(u - 1, v - 1, 1)
            graph.add_edge(v - 1, u - 1, 1)
    return graph

def write_result_to_file(vertex_connectivity, filename):
    with open(filename, 'a') as file:
        file.write(f"\nVertex connectivity is {vertex_connectivity}\n")

def main():
    filename = "G.txt"

    # Read graph from file
    g = read_graph_from_file(filename)

    s = 0
    t = g.V - 1

    # Find vertex connectivity
    if g.has_isolated_vertex():
        vertex_connectivity = 0
    else:
        vertex_connectivity = g.max_flow(s, t)

    # Write the result to a file
    write_result_to_file(vertex_connectivity, filename)

if __name__ == '__main__':
    main()

