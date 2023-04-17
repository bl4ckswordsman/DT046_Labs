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

/** @param node: the node to start the dfs from
 * @param adj_list: the adjacency list of the graph
 * @return a vector of size adj_list.size() where the visited nodes are marked */
std::vector<int> dfs(int node, const std::vector<std::vector<std::pair<int, double>>> &adj_list);


#endif //DT046_L1_DFS_H