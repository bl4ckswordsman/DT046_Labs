// dfs.h
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

void dfs(int node, const std::vector<std::vector<std::pair<int, double>>> &adj_list, std::vector<int> &visited);

bool is_graph_connected(const std::vector<std::vector<std::pair<int, double>>> &adj_list);

std::vector<int> get_disconnected_nodes(const std::vector<int> &visited);


#endif //DT046_L1_DFS_H