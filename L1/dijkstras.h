//
// Created by amarildo on 2023-04-05.
//

#ifndef DT046_L1_DIJKSTRAS_H
#define DT046_L1_DIJKSTRAS_H

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include "reader.h"

/** @param start: the node to start the dijkstras from
 * @param end: the node to end the dijkstras at
 * @param adj_list: the adjacency list of the graph
 * @return a vector of size adj_list.size() where the visited nodes are marked */
double dijkstras(int start, int end, const adjacency_list_t &adj_list);



#endif //DT046_L1_DIJKSTRAS_H
