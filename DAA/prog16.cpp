//Program 16 - Kruskal Algorithm

#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// Define a structure to represent a subset for union-find algorithm
struct Subset {
    int parent, rank;
};

// Comparator function to sort edges in non-decreasing order of their weight
bool cmp(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the parent of a subset using path compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets using rank
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to implement Kruskal's algorithm
void Kruskal(vector<Edge> edges, int V) {
    // Sort the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), cmp);

    // Allocate memory for subsets
    Subset *subsets = new Subset[V];

    // Initialize subsets
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Initialize variables
    vector<Edge> MST;
    int edge_count = 0;

    // Iterate through all edges in non-decreasing order
    for (auto it = edges.begin(); it != edges.end() && edge_count < V - 1; it++) {
        // Find the parent of the source and destination vertices
        int x = find(subsets, it->src);
        int y = find(subsets, it->dest);

        // If including this edge does not form a cycle, include it in MST and increment edge_count
        if (x != y) {
            MST.push_back(*it);
            Union(subsets, x, y);
            edge_count++;
        }
    }

    // Print MST
    cout << "Edges in MST:\n";
    for (auto it = MST.begin(); it != MST.end(); it++)
        cout << it->src << " - " << it->dest << " : " << it->weight << endl;

    // Free memory
    delete[] subsets;
}

int main() {
    // Get input from user
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges;
    cout << "Enter the source, destination and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        Edge edge;
        cin >> edge.src >> edge.dest >> edge.weight;
        edges.push_back(edge);
    }

    // Find MST using Kruskal's algorithm
    Kruskal(edges, V);

    return 0;
}


// Enter the number of vertices: 6
// Enter the number of edges: 9
// Enter the source, destination and weight of each edge:
// 0 1 4
// 0 2 3
// 1 2 1
// 1 3 2
// 2 3 4
// 3 4 2
// 4 5 6
// 3 5 3
// 2 4 5
// Edges in MST:
// 1 - 2 : 1
// 1 - 3 : 2
// 3 - 4 : 2
// 0 - 2 : 3
// 3 - 5 : 3
// 4 - 5 : 6
