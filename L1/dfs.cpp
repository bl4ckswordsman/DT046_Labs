// dfs.cpp
//
// Created by amarildo on 2023-04-05.
//

#include "dfs.h"


std::vector<int> dfs(int node, adjacency_list_t& adj_list) {
    std::vector<int> visited(adj_list.first.size(), NOT_VISITED);
    std::stack<int> s;
    s.push(node);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (visited[curr] == NOT_VISITED) {
            visited[curr] = VISITED;

            for (const auto& edge : adj_list.second) {
                int neighbor = edge.n2;
                double weight = edge.weight;
                if (edge.n1 == curr && weight != NOT_CONNECTED && visited[neighbor] == NOT_VISITED) {
                    s.push(neighbor);
                }
            }
        }
    }

    return visited;
}


