//
// Created by amarildo on 2023-04-05.
//

#include "bfs.h"

const int NOT_VISITED = 0;
const int VISITED = 1;
const int NOT_CONNECTED = -1;

// Perform a breadth first search on the graph starting at node and mark all visited nodes in visited
void bfs(int node, const std::vector<std::vector<std::pair<int, double>>> &adj_list, std::vector<int> &visited) {
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
            for (const auto &edge: adj_list[curr]) {
                if (edge.second != NOT_CONNECTED) {
                    if (visited[edge.first] == NOT_VISITED) {
                        q.push(edge.first);
                    }
                }
            }
        }
    }
}