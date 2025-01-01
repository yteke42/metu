#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;
/*
Implement the Graph class functions declared in Graph.h in this file.
Don't define global functions.
Don't define global variables.
*/



// Edge.h
// DO NOT MODIFY THIS FILE
class Edge
{
public:
   int node1;
   int node2;
   int length;
};

//Graph.h
/*
   DON'T CHANGE THE EXISTING FUNCTION SIGNATURES AND VARIABLE NAMES
   IF YOU NEED, YOU CAN ADD NEW FUNCTIONS AND VARIABLES
*/
class Graph
{
private:
   /*
   Since arrays are indeed pointers, you may use a double pointer as a matrix.
   You can allocate it using new or malloc (multiple new or malloc operations may be needed.).
   */
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


Graph::Graph(Edge* edges_array, int num_nodes, int num_edges) {
    this->num_nodes = num_nodes;
    this->num_edges = num_edges;

    // Initialize the adjacency matrix
    adjMatrix = new int*[num_nodes];
    for (int i = 0; i < num_nodes; ++i) {
        adjMatrix[i] = new int[num_nodes];
        memset(adjMatrix[i], 0, num_nodes * sizeof(int));
    }

    // Fill the adjacency matrix
    for (int i = 0; i < num_edges; ++i) {
        int u = edges_array[i].node1;
        int v = edges_array[i].node2;
        int length = edges_array[i].length;
        adjMatrix[u][v] = length;
        adjMatrix[v][u] = length;  // because the graph is undirected
    }
}

Graph::~Graph() {
    for (int i = 0; i < num_nodes; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}


int* Graph::dijkstra(int source) {
    int* dist = new int[num_nodes];
    bool* visited = new bool[num_nodes];

    for (int i = 0; i < num_nodes; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < num_nodes - 1; ++count) {
        // Find the minimum distance node from the set of vertices not yet processed.
        int min = INT_MAX, min_index;
        for (int v = 0; v < num_nodes; ++v) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v], min_index = v;
            }
        }

        int u = min_index;
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < num_nodes; ++v) {
            if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    for (int i = 0; i < num_nodes; ++i) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
    }

    delete[] visited;
    return dist;
}



void Graph::DFS(int** adjMatrix, int num_nodes, int v, bool* visited, int* component, int& size) {
    visited[v] = true;
    component[size++] = v;

    for (int i = 0; i < num_nodes; ++i) {
        if (adjMatrix[v][i] && !visited[i]) {
            DFS(adjMatrix, num_nodes, i, visited, component, size);
        }
    }
}

int findCentroid(int** adjMatrix, int num_nodes, int* component, int size) {
    int min_sum = INT_MAX, centroid = -1;

    for (int i = 0; i < size; ++i) {
        int sum = 0;
        int* dist = new int[num_nodes];
        bool* visited = new bool[num_nodes];

        for (int j = 0; j < num_nodes; ++j) {
            dist[j] = INT_MAX;
            visited[j] = false;
        }

        dist[component[i]] = 0;

        for (int count = 0; count < num_nodes - 1; ++count) {
            int min = INT_MAX, min_index;
            for (int v = 0; v < num_nodes; ++v) {
                if (!visited[v] && dist[v] <= min) {
                    min = dist[v], min_index = v;
                }
            }

            int u = min_index;
            visited[u] = true;

            for (int v = 0; v < num_nodes; ++v) {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        for (int j = 0; j < size; ++j) {
            sum += dist[component[j]];
        }

        if (sum < min_sum) {
            min_sum = sum;
            centroid = component[i];
        }

        delete[] dist;
        delete[] visited;
    }

    return centroid;
}


int* Graph::get_centroids() {
    bool* visited = new bool[num_nodes];
    memset(visited, false, num_nodes * sizeof(bool));

    int* centroids = new int[num_nodes + 1];
    int centroid_count = 0;

    for (int v = 0; v < num_nodes; ++v) {
        if (!visited[v]) {
            int* component = new int[num_nodes];
            int size = 0;
            DFS(adjMatrix, num_nodes, v, visited, component, size);

            int centroid = findCentroid(adjMatrix, num_nodes, component, size);
            centroids[++centroid_count] = centroid;

            delete[] component;
        }
    }

    delete[] visited;

    centroids[0] = centroid_count;
    std::sort(centroids + 1, centroids + centroid_count + 1);

    return centroids;
}

int Graph::get_centroid_of_connected_component_containing(int node) {
    bool* visited = new bool[num_nodes];
    memset(visited, false, num_nodes * sizeof(bool));

    int* component = new int[num_nodes];
    int size = 0;
    DFS(adjMatrix, num_nodes, node, visited, component, size);

    int centroid = findCentroid(adjMatrix, num_nodes, component, size);

    delete[] visited;
    delete[] component;

    return centroid;
}

int* Graph::nodes_in_connected_component_with_centroid(int centroid_node) {
    bool* visited = new bool[num_nodes];
    memset(visited, false, num_nodes * sizeof(bool));

    int* component = new int[num_nodes];
    int size = 0;
    DFS(adjMatrix, num_nodes, centroid_node, visited, component, size);

    int centroid = findCentroid(adjMatrix, num_nodes, component, size);
    if (centroid != centroid_node) {
        delete[] visited;
        delete[] component;
        int* result = new int[1];
        result[0] = 0;
        return result;
    }

    int* result = new int[size + 1];
    result[0] = size;
    std::sort(component, component + size);
    for (int i = 0; i < size; ++i) {
        result[i + 1] = component[i];
    }

    delete[] visited;
    delete[] component;

    return result;
}


int main() {
    // Define edges
    Edge edges_array[10] = {
        {0, 1, 3},
        {0, 3, 3},
        {0, 4, 1},
        {2, 1, 3},
        {2, 4, 1},
        {2, 3, 3},
        {1, 4, 1},
        {4, 3, 1},
        {5, 6, 12},
        {5, 7, 18}
    };
    int num_nodes = 8;
    int num_edges = 10;

    // Create graph
    Graph graph(edges_array, num_nodes, num_edges);

    for(int i = 0; i < num_nodes; i++)
    {
        int *distances = graph.dijkstra(i);
        for(int j =0; j < num_nodes; j++)
        {
            if(distances[j] == -1)
                cout<<"It is not possible to reach from node "<<i<<" to node "<<j<<"."<<endl; 
            else
                cout<<"Distance from node "<<i<<" to node "<<j<<" is "<<distances[j]<<"."<<endl;
        }
        delete distances;
    }
    
    int* centroids = graph.get_centroids();
    int num_centroids = centroids[0];
    cout<<"Number of connected components is: "<<num_centroids<<endl;
    
    for(int i = 1; i <= num_centroids; i++)
    {
        cout<<"Nodes in the connected component with centroid "<<centroids[i]<<" is:"<<endl;
        int *nodes = graph.nodes_in_connected_component_with_centroid(centroids[i]);
        for (int j = 1; j<= nodes[0];j++)
            cout<<nodes[j]<<" ";
        cout<<endl;
        delete nodes;
    }
    
    for(int i = 0; i < num_nodes; i++)
    {
        cout<<"Centroid node of the connected component containing the node "<<i<<" is: node "<<graph.get_centroid_of_connected_component_containing(i)<<endl;
    }
    return 0;
}