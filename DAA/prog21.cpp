//Program 21 - Ford-Fulkerson algo

#include <bits/stdc++.h>  // Include all standard libraries
using namespace std;

// A structure to represent a directed edge between two vertices
struct Edge {
    int u, v, w;  // 'u' is the source vertex, 'v' is the destination vertex and 'w' is the weight of the edge
};

// A function to find the maximum flow from source 's' to sink 't' in a graph represented by adjacency matrix 'graph'
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();  // Get the number of vertices in the graph

    // Initialize the residual graph with the same capacities as the original graph
    vector<vector<int>> residualGraph(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            residualGraph[i][j] = graph[i][j];
        }
    }

    // Initialize the parent array for BFS
    vector<int> parent(V);

    int maxFlow = 0;  // Initialize the maximum flow to 0

    // Augment the flow while there is a path from source to sink in the residual graph
    while (true) {
        // Use BFS to find a path from source to sink in the residual graph
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(s);
        parent[s] = -2;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < V; v++) {
                if (parent[v] == -1 && residualGraph[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // If there is no path from source to sink in the residual graph, we have reached the maximum flow
        if (parent[t] == -1) {
            break;
        }

        // Find the bottleneck capacity of the augmenting path
        int bottleneckCapacity = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            bottleneckCapacity = min(bottleneckCapacity, residualGraph[u][v]);
        }

        // Update the residual capacities of the edges and reverse edges along the augmenting path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= bottleneckCapacity;
            residualGraph[v][u] += bottleneckCapacity;
        }

        // Add the bottleneck capacity to the maximum flow
        maxFlow += bottleneckCapacity;
    }

    // Return the maximum flow
    return maxFlow;
}

int main() {
    int V, E, s, t;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Initialize the graph as an adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V));

    // Take input for all the edges
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cout << "Enter the source, destination and weight of edge " << i+1 << ": ";
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // Take input for source and sink
    cout << "Enter the source vertex: ";
    cin >> s;
    cout << "Enter the sink vertex: ";
    cin >> t;

    int maxFlow = fordFulkerson(graph, s, t);  // Calculate the maximum flow using the Ford-Fulkerson Algorithm

    cout << "The maximum flow from vertex " << s << " to vertex " << t << " is: " << maxFlow << endl;  // Output the maximum flow

    return 0;  // Return 0 to indicate successful completion of the program
}


// The test case is a directed graph with 6 vertices and 10 edges. Each edge has a weight or capacity, which is shown in parentheses next to the edge. The edges are as follows:
// 0 -> 1 (16)
// 0 -> 2 (13)
// 1 -> 3 (12)
// 2 -> 1 (4)
// 2 -> 4 (14)
// 3 -> 2 (9)
// 3 -> 5 (20)
// 4 -> 3 (7)
// 4 -> 5 (4)
// We want to find the maximum flow from vertex 0 to vertex 5.
// -------------------------------------------------------------------------------
// Enter the number of vertices: 6
// Enter the number of edges: 10
// Enter the details of each edge [start vertex] [end vertex] [weight]:
// 0 1 16
// 0 2 13
// 1 3 12
// 2 1 4 
// 2 4 14
// 3 2 9
// 3 5 20
// 4 3 7
// 4 5 4
// Enter the source vertex: 0
// Enter the sink vertex: 5
// The maximum flow from vertex 0 to vertex 5 is: 23
