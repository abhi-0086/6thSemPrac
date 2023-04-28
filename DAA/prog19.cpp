//Program 19 - Dijkstra

#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;

void dijkstra(int graph[MAX_SIZE][MAX_SIZE], int n, int start) {
    int dist[MAX_SIZE]; // array to store shortest distances from start to all vertices
    bool visited[MAX_SIZE]; // array to track visited vertices
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX; // initialize distances to "infinity"
        visited[i] = false; // initialize visited array to false
    }
    dist[start] = 0; // distance from start to itself is 0

    // iterate n-1 times (once for each vertex)
    for (int i = 0; i < n-1; i++) {
        // find the vertex with the minimum distance from start
        int min_dist = INT_MAX;
        int min_vertex;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_vertex = j;
            }
        }
        visited[min_vertex] = true; // mark vertex as visited

        // update distances of adjacent vertices
        for (int k = 0; k < n; k++) {
            int weight = graph[min_vertex][k];
            if (weight != 0 && dist[min_vertex] != INT_MAX && dist[min_vertex] + weight < dist[k]) {
                dist[k] = dist[min_vertex] + weight;
            }
        }
    }

    // print shortest distances
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n; // number of vertices
    int graph[MAX_SIZE][MAX_SIZE]; // adjacency matrix
    int start; // starting vertex

    // get user input
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the starting vertex: ";
    cin >> start;

    // run Dijkstra's algorithm
    dijkstra(graph, n, start);

    return 0;
}


// Enter the number of vertices: 5
// Enter the adjacency matrix (0 for no edge):
// 0 1 1 1 0
// 1 0 0 1 0
// 1 0 0 0 1
// 1 1 0 0 0
// 0 0 1 0 0
// Enter the starting vertex: 1
// Shortest distances from vertex 1:
// 0: 0
// 1: 1
// 2: 1
// 3: 1
// 4: 2
