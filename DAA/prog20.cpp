//Program 20 - Flyod Wrashall Algo

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9; // a large value to represent infinity

int main() {
    int n, m;
    cout << "Enter the number of vertices (n) and edges (m) in the graph: ";
    cin >> n >> m;

    // initialize adjacency matrix
    vector<vector<int>> adj(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; i++) {
        adj[i][i] = 0; // set diagonal elements to 0
    }

    // take input for edges and their weights
    cout << "Enter the edges and their weights in the format (u, v, w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // print the final shortest distances
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << adj[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

// Enter the number of vertices (n) and edges (m) in the graph: 4 5
// Enter the edges and their weights in the format (u, v, w):
// 1 2 5
// 1 4 9
// 2 3 2
// 3 1 7
// 3 4 1

// Shortest distances between all pairs of vertices:
// 0 5 7 9 
// 7 0 2 4 
// 3 8 0 1 
// 5 10 12 0 
