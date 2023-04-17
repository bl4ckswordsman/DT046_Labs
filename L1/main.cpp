#include <iostream>
#include <vector>
#include <stack>
#include "reader.h"
#include "dfs.h"
#include "bfs.h"
#include "dijkstras.h"

bool is_graph_connected(const std::vector<int> &visited) {
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == NOT_VISITED) {
            return false;
        }
    }
    return true;
}

void print_disconnected_nodes(const std::vector<int>& visited) {
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == NOT_VISITED) {
            std::cout << "Node " << i << " is not visited." << std::endl;
        }
    }
}


int main() {
    // Read file and create edge list from it
    auto file_data = parse_file("../edges.txt");
    auto meta = file_data.first;
    auto edge_list = file_data.second;

// Create adjacency list from edge list
    std::vector<std::vector<std::pair<int, double>>> adj_list(meta.size());
    for (const auto& edge : edge_list) {
        adj_list[edge.n1].emplace_back(edge.n2, edge.weight);
    }

    auto visited_graph = dfs2(0, file_data);//= dfs(0, adj_list);
// Check if graph is connected
    if (is_graph_connected(visited_graph)) {
        std::cout << "Graph is connected." << std::endl;
    } else {
        std::cout << "Graph is not connected." << std::endl;
        print_disconnected_nodes(visited_graph);
    }

        // Dijkstra's algorithm
    auto start_node = 0;
    auto end_node = 19;
    auto distance = dijkstras(start_node,end_node, adj_list);
    std::cout << "Distance from " << start_node << " to " << end_node << ": " << distance << std::endl;

    return 0;
}