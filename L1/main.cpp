#include <iostream>
#include <vector>
#include <stack>
#include "reader.h"
#include "dfs.h"
#include "bfs.h"
#include "dijkstras.h"

std::vector<int> get_disconnected_nodes(const std::vector<int> &visited) {
    std::vector<int> disconnected_nodes;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == NOT_VISITED) {
            disconnected_nodes.push_back(i);
        }
    }
    return disconnected_nodes;
}

bool is_graph_connected(const std::vector<std::vector<std::pair<int, double>>> &adj_list) {
    std::vector<int> visited(adj_list.size(), NOT_VISITED);
    //dfs(0, adj_list, visited);

    for (const auto &v: visited) {
        if (v == NOT_VISITED) {
            return false;
        }
    }
    return true;
}


int main() {
    // Parse file and create adjacency list from it (adj_list) and meta data (meta) from it (meta)
    // The meta data is a map from node id to node name (e.g. 0 -> "A") and is used to print the node names instead of the node ids
    // The adjacency list is a vector of vectors of pairs (e.g. adj_list[0] = {{1, 1.0}, {2, 2.0}} means that node 0 is connected to node 1 with weight 1.0 and node 2 with weight 2.0)
    // The adjacency list is created from the edge list (e.g. edge_list = {{0, 1, 1.0, "Edge 0 to 1"}, {0, 2, 2.0, "Edge 0 to 2"}})
    // The edge list is created from the file edges.txt
    auto [meta, edge_list] = parse_file("../edges.txt");

    std::vector<std::vector<std::pair<int, double>>> adj_list(meta.size());
    for (const auto& edge : edge_list) {
        adj_list[edge.n1].emplace_back(edge.n2, edge.weight);
    }

    if (is_graph_connected(adj_list)) {
        std::cout << "Graph is connected." << std::endl;
    }
    else {
        std::cout << "Graph is not connected." << std::endl;
        std::cout << "Disconnected nodes: ";
        // Run DFS again to find disconnected nodes and print them
        std::vector<int> visited(meta.size(), NOT_VISITED);
        auto visited_nodes = dfs(0, adj_list);
        // Print disconnected nodes
        for (const auto &node: get_disconnected_nodes(visited_nodes)) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    auto distance = dijkstras(0,19, adj_list);
    //std::cout << "Distance from 0 to 3: " << distance << std::endl;

    return 0;
}