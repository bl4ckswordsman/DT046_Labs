#include <iostream>
#include <vector>
#include <stack>
#include "reader.h"
#include "dfs.h"


int main() {
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
        dfs(0, adj_list, visited);
        // Print disconnected nodes
        for (const auto &node: get_disconnected_nodes(visited)) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}