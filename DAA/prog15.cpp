//Program 15 - Breadth First Search

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, int start) {  // pass graph by reference
    // Initialize an empty queue and a vector to store visited nodes
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    // Mark the starting node as visited and push it to the queue
    visited[start] = true;
    q.push(start);

    // Continue searching until the queue is empty
    while (!q.empty()) {
        // Get the first node in the queue and remove it from the queue
        int node = q.front();
        q.pop();
        cout << node << " ";  // print the node

        // Iterate through the neighbors of the current node
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];
            // If the neighbor has not been visited, mark it as visited and add it to the queue
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Prompt the user to input the number of nodes and edges
    cout << "Enter the number of nodes and edges: ";
    int n, m;
    cin >> n >> m;

    // Create an adjacency list to represent the graph
    vector<vector<int>> graph(n);
    // Read each edge and add it to the adjacency list
    cout << "Enter the edges (as pairs of integers representing the endpoints):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= n || v >= n) {  // check if node number is valid
            cout << "Invalid node number!" << endl;
            return 1;
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Read the starting node from the input
    cout << "Enter the starting node: ";
    int start;
    cin >> start;
    if (start >= n) {  // check if node number is valid
        cout << "Invalid starting node!" << endl;
        return 1;
    }

    // Call the BFS function with the graph and starting node
    bfs(graph, start);
    cout << endl;

    return 0;
}


// Enter the number of nodes and edges: 6 7
// Enter the edges (as pairs of integers representing the endpoints):
// 0 1
// 0 2
// 1 2
// 2 3
// 3 4
// 4 5
// 5 3
// Enter the starting node: 0
// 0 1 2 3 4 5
