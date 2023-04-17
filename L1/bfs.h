//
// Created by amarildo on 2023-04-05.
//

#ifndef DT046_L1_BFS_H
#define DT046_L1_BFS_H

#include <vector>
#include <queue>
#include "reader.h"


/** @param node: the node to start the bfs from
 * @param adj_list: the adjacency list of the graph
 * @return a vector of size adj_list.size() where the visited nodes are marked */
std::vector<int> bfs(int node, const adjacency_list_t &adj_list);

#endif //DT046_L1_BFS_H
