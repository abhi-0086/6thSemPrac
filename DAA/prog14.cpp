//program 14 - Depth First Search

    #include<bits/stdc++.h>
    using namespace std;

    // Function to perform DFS
    void DFS(vector<vector<int>> graph, int start) {
        // Create a stack for DFS
        stack<int> s;
        // Create a visited array to keep track of visited nodes
        vector<bool> visited(graph.size(), false);

        // Push the starting node onto the stack
        s.push(start);
        while (!s.empty()) {
            // Pop a node from the stack and mark it as visited
            int node = s.top();
            s.pop();
            visited[node] = true;
            // Print the node
            cout << node << " ";
            // Push all unvisited neighbors of the node onto the stack
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    // Driver code
    int main() {
        int n;
        cout << "Enter the number of nodes in the graph: ";
        cin >> n;

        // Create a graph
        vector<vector<int>> graph(n);

        int m;
        cout << "Enter the number of edges in the graph: ";
        cin >> m;

        for (int i = 0; i < m; i++) {
            int u, v;
            cout << "Enter an edge (u v): ";
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int start;
        cout << "Enter the starting node for DFS: ";
        cin >> start;

        // Perform DFS starting from the given node
        DFS(graph, start);
        cout <<endl;

        return 0;
    }
