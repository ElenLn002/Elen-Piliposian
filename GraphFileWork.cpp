#include <fstream> //std::istream, std::ofstream
#include <iostream> //std::cout, std::endl
#include <string> //std::string

#include "GraphFileWork.hpp"

Graph readGraphFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        exit(1);
    }

    int V, E;
    file >> V >> E;  // Read number of vertices and edges

    Graph graph(V);

    int u, v;
    for (int i = 0; i < E; i++) {
        file >> u >> v;
        graph.add_edge(u - 1, v - 1, 1);
        graph.add_edge(v - 1, u - 1, 1);
    }

    file.close();

    return graph;
}

// Write the result to a text file
void writeResultToFile(int vertexConnectivity, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Failed to create file: " << filename << std::endl;
        //exit(1);
    }
    
    file << "\nVertex connectivity is " << vertexConnectivity << std::endl;

    file.close();
}

