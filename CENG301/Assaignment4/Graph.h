//Graph.h
/*
    DON'T CHANGE THE EXISTING FUNCTION SIGNATURES AND VARIABLE NAMES
    IF YOU NEED, YOU CAN ADD NEW FUNCTIONS AND VARIABLES
*/
#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"

class Graph
{
private:
    int** adjMatrix;
    int num_nodes;
    int num_edges;
    /* ADD MORE PRIVATE VARIABLES/FUNCTIONS IF NEEDED */
    
public:
    Graph (Edge* edges_array, int num_nodes, int num_edges);
    ~Graph();

    int* dijkstra(int source);
    int* get_centroids();
    int get_centroid_of_connected_component_containing(int node);
    int* nodes_in_connected_component_with_centroid (int centroid_node);
    /* ADD MORE PUBLIC FUNCTIONS IF NEEDED */

   void DFS(int** adjMatrix, int num_nodes, int v, bool* visited, int* component, int& size);

    
};
#endif