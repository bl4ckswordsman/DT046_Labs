//
// Created by amarildo on 2023-04-05.
//

#include "bfs.h"

const int NOT_VISITED = 0;
const int VISITED = 1;
const int NOT_CONNECTED = -1;



std::vector<int> bfs(int node, const adjacency_list_t &adj_list) {
    std::vector<int> handled_nodes_v(adj_list.first.size(), NOT_VISITED);
    std::queue<int> nodes_q;
    nodes_q.push(node);
    // Mark the starting node as handled_nodes_v
    while (!nodes_q.empty()) {
        int curr = nodes_q.front();
        nodes_q.pop();
        // If the node has not been visited, mark it as visited and push all its neighbors to the queue
        if (handled_nodes_v[curr] == NOT_VISITED) {
            handled_nodes_v[curr] = VISITED;
            // Push all neighbors to the queue
            for (const auto &edge: adj_list.second) {
                int neighbor = edge.n2;
                double weight = edge.weight;
                if (edge.n1 == curr && weight != NOT_CONNECTED) {  //  && handled_nodes_v[neighbor] == NOT_VISITED
                    nodes_q.push(neighbor);
                }
            }
        }
    }

    return handled_nodes_v;
}
