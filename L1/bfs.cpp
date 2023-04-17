//
// Created by amarildo on 2023-04-05.
//

#include "bfs.h"

const int NOT_VISITED = 0;
const int VISITED = 1;
const int NOT_CONNECTED = -1;



std::vector<int> bfs(int node, const adjacency_list_t &adj_list) {
    std::vector<int> visited(adj_list.first.size(), NOT_VISITED);
    std::queue<int> q;
    q.push(node);
    // Mark the starting node as visited
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        // If the node has not been visited, mark it as visited and push all its neighbors to the queue
        if (visited[curr] == NOT_VISITED) {
            visited[curr] = VISITED;
            // Push all neighbors to the queue
            for (const auto &edge: adj_list.second) {
                int neighbor = edge.n2;
                double weight = edge.weight;
                if (edge.n1 == curr && weight != NOT_CONNECTED && visited[neighbor] == NOT_VISITED) {
                    q.push(neighbor);
                }
            }
        }
    }

    return visited;
}
