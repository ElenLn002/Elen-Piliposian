#include <algorithm> //std::fill, std::min
#include <climits> //INT_MAX
#include <cstring> //std::string
#include <fstream> //std::istream, std::ofstream
#include <iostream> //std::cout, std::endl
#include <queue> //std::queue
#include <vector> //std::vector std::empty

#include "GraphFileWork.hpp"

int main() {
    std::string filename = "Graph.txt";

    
    // Read graph from file
    Graph g = readGraphFromFile(filename);

    int s = 0, t = g.V - 1;

    // Find vertex connectivity
    int vertexConnectivity;
    if(g.has_isolated_vertex()){
        vertexConnectivity = 0;
    }
    else{
    vertexConnectivity = g.max_flow(s, t);
    }

    // Write the result to a file
    writeResultToFile(vertexConnectivity, filename);

    return 0;
}

