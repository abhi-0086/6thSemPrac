//Program 18 - Bellman Ford algo

#include<bits/stdc++.h>
using namespace std;

// A structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// A structure to represent the graph
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// A utility function to print the solution
void printSolution(vector<int> dist) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < dist.size(); i++) {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

// The main function that finds the shortest distance from the source vertex to all other vertices
void BellmanFord(Graph graph, int src) {
    int V = graph.V;
    int E = graph.E;
    vector<int> dist(V, numeric_limits<int>::max()); // Initialize distance from the source vertex to all vertices as infinite
    dist[src] = 0; // Initialize distance from the source vertex to itself as 0

    // Relax all edges V - 1 times to find the shortest path from the source vertex to all other vertices
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph.edges[j].src;
            int v = graph.edges[j].dest;
            int weight = graph.edges[j].weight;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = graph.edges[i].src;
        int v = graph.edges[i].dest;
        int weight = graph.edges[i].weight;
        if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative-weight cycle\n";
            return;
        }
    }

    // Print the solution
    printSolution(dist);
}

int main() {
    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    Graph graph = {V, E, {}};

    for (int i = 0; i < E; i++) {
        Edge edge;
        cout << "Enter the source vertex, destination vertex, and weight of edge " << i+1 << ": ";
        cin >> edge.src >> edge.dest >> edge.weight;
        graph.edges.push_back(edge);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    BellmanFord(graph, src);

    return 0;
}


// Enter the number of vertices in the graph: 5
// Enter the number of edges in the graph: 8
// Enter the source vertex, destination vertex, and weight of edge 1: 0 1 6
// Enter the source vertex, destination vertex, and weight of edge 2: 0 3 2
// Enter the source vertex, destination vertex, and weight of edge 3: 1 2 1
// Enter the source vertex, destination vertex, and weight of edge 4: 2 4 4
// Enter the source vertex, destination vertex, and weight of edge 5: 2 1 3
// Enter the source vertex, destination vertex, and weight of edge 6: 3 1 3
// Enter the source vertex, destination vertex, and weight of edge 7: 3 4 6
// Enter the source vertex, destination vertex, and weight of edge 8: 4 3 3
// Enter the source vertex: 0


// Vertex   Distance from Source
// 0                0
// 1                6
// 2                7
// 3                2
// 4                10
