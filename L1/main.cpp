#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include "reader.h"
#include "dfs.h"



int main() {
    auto [meta, edge_list] = parse_file("../edges.txt");

    std::vector<std::vector<std::pair<int, double>>> adj_list(meta.size());
    for (const auto& edge : edge_list) {
        adj_list[edge.n1].push_back({edge.n2, edge.weight});
    }

    if (is_graph_connected(adj_list)) {
        std::cout << "Graph is connected." << std::endl;
    }
    else {
        std::vector<int> disconnected_nodes = dfs_stack(adj_list);
        if (disconnected_nodes.empty()) {
            std::cout << "Graph is connected." << std::endl;
        }
        else {
            std::cout << "Disconnected nodes:";
            for (const auto& node : disconnected_nodes) {
                std::cout << " " << node;
            }
            std::cout << std::endl;
        }
    }



    return 0;
}