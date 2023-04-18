// dfs.cpp
//
// Created by amarildo on 2023-04-05.
//

#include "dfs.h"


std::vector<int> dfs(int node, adjacency_list_t& adj_list) {
    // Create a vector of size adj_list.size() and initialize it with NOT_VISITED
    std::vector<int> handled_nodes_v(adj_list.first.size(), NOT_VISITED);
    // Create a stack and push the starting node to it (LIFO)
    std::stack<int> nodes_s;
    nodes_s.push(node);
    // Mark the starting node as handled_nodes_v and pop it from the stack
    while (!nodes_s.empty()) {
        int curr = nodes_s.top();
        nodes_s.pop();
        // If the node has not been visited, mark it as visited and push all its neighbors to the stack
        if (handled_nodes_v[curr] == NOT_VISITED) {
            handled_nodes_v[curr] = VISITED;
            // Push all neighbors to the stack
            for (const auto& edge : adj_list.second) {
                int neighbor = edge.n2;
                double weight = edge.weight;
                if (edge.n1 == curr && weight != NOT_CONNECTED) {  //  && handled_nodes_v[neighbor] == NOT_VISITED
                    nodes_s.push(neighbor);
                }
            }
        }
    }

    return handled_nodes_v;
}


