//Program 17 - Prim's Algorithm

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

vector<pair<int,int>> adj[MAXN]; // adjacency list of the graph
bool visited[MAXN]; // array to keep track of visited vertices

// function to add a directed edge from vertex u to vertex v with weight w
void add_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
}

int prim(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int minCost = 0;
    pq.push({0, start}); // start with vertex 0 and cost 0

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if (visited[u]) continue; // if vertex is already visited, skip it
        visited[u] = true;
        minCost += w;

        for (auto v : adj[u]) {
            if (!visited[v.first]) {
                pq.push({v.second, v.first});
            }
        }
    }

    return minCost;
}

int main() {
    int n, m; // number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    // read in the edges of the graph
    cout << "Enter the edges of the graph in the format 'u v w':\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    int start = 0; // start with vertex 0
    int minCost = prim(start);

    cout << "Minimum cost of spanning tree: " << minCost << endl;

    return 0;
}

// Enter the number of vertices and edges: 4 5
// Enter the edges of the graph in the format 'u v w':
// 0 1 2
// 0 2 3
// 1 2 1
// 1 3 4
// 2 3 5

// Here's the output:

// Minimum cost of spanning tree: 6