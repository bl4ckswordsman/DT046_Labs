#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <fstream>
#include "reader.h"

using namespace std;

void dfs(const vector<vector<int>>& adj_list, vector<bool>& visited, int node) {
    visited[node] = true;

    for (int i = 0; i < adj_list[node].size(); ++i) {
        int neighbor = adj_list[node][i];
        if (!visited[neighbor]) {
            dfs(adj_list, visited, neighbor);
        }
    }
}

void check_validity(const adjacency_list_t& adj_list) {
    int num_nodes = 0;

    // Calculate the number of nodes in the graph
    for (const auto& e : adj_list.second) {
        num_nodes = max(num_nodes, max(e.n1, e.n2));
    }
    num_nodes++; // Increment to get the actual number of nodes

    // Convert edge list to adjacency list
    vector<vector<int>> adj(num_nodes);
    for (auto& e : adj_list.second) {
        adj[e.n1].push_back(e.n2);
        adj[e.n2].push_back(e.n1);
    }

    vector<bool> visited(num_nodes, false);

    // Run DFS on first node
    dfs(adj, visited, 0);

    // Check if all nodes were visited
    bool valid = true;
    for (int i = 0; i < num_nodes; ++i) {
        if (!visited[i]) {
            cout << "Graph is not connected. Node " << i << " is not reachable from Node 0." << endl;
            valid = false;
        }
    }

    if (valid) {
        cout << "Graph is valid." << endl;
    }
}


int main() {
    // Parse the input file and get adjacency list
    adjacency_list_t adj_list = parse_file("../edges.txt");


    // Check if the graph is valid
    check_validity(adj_list);

    return 0;
}