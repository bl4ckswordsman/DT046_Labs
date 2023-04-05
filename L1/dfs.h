//
// Created by amarildo on 2023-04-03.
//

#ifndef DT046_L1_DFS_H
#define DT046_L1_DFS_H

#include <vector>
#include <stack>

const int NOT_VISITED = 0;
const int VISITED = 1;
const int NOT_CONNECTED = -1;

void dfs(int node, const std::vector<std::vector<std::pair<int, double>>> &adj_list, std::vector<int> &visited) {
    std::stack<int> s;
    s.push(node);

    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        if (visited[curr] == NOT_VISITED) {
            visited[curr] = VISITED;

            for (const auto &edge: adj_list[curr]) {
                if (edge.second != NOT_CONNECTED) {
                    if (visited[edge.first] == NOT_VISITED) {
                        s.push(edge.first);
                    }
                }
            }
        }
    }
}

bool is_graph_connected(const std::vector<std::vector<std::pair<int, double>>> &adj_list) {
    std::vector<int> visited(adj_list.size(), NOT_VISITED);
    dfs(0, adj_list, visited);


    for (const auto &v: visited) {
        if (v == NOT_VISITED) {
            return false;
        }
    }
    return true;
}

std::vector<int> get_disconnected_nodes(const std::vector<int> &visited) {
    std::vector<int> disconnected_nodes;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == NOT_VISITED) {
            disconnected_nodes.push_back(i);
        }
    }
    return disconnected_nodes;
}


#endif //DT046_L1_DFS_H