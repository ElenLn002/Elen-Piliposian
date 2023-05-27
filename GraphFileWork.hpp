#ifndef GRAPHFILEWORK_HPP
#define GRAPHFILEWORK_HPP

#include <string> //std::string

#include "Graph.hpp"

//Read the result from a text file
Graph readGraphFromFile(const std::string& filename);

// Write the result to a text file
void writeResultToFile(int vertexConnectivity, const std::string& filename);

#endif //GRAPHFILEWORK_HPP
