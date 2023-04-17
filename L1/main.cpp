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


        // DFS
    std::cout << "\tDFS:" << std::endl;
    auto visited_graph_dfs = dfs(0, file_data);

    // Check if graph is connected
    if (is_graph_connected(visited_graph_dfs)) {
        std::cout << "Graph is connected." << std::endl;
    } else {
        std::cout << "Graph is not connected." << std::endl;
        print_disconnected_nodes(visited_graph_dfs);
    }

        // BFS
    std::cout << "\tBFS:" << std::endl;
    auto visited_graph_bfs = bfs(0, file_data);
    // Check if graph is connected
    if (is_graph_connected(visited_graph_bfs)) {
        std::cout << "Graph is connected." << std::endl;
    } else {
        std::cout << "Graph is not connected." << std::endl;
        print_disconnected_nodes(visited_graph_bfs);
    }

        // Dijkstra's algorithm
    std::cout << "\tDijkstra's algorithm:" << std::endl;
    auto start_node = 0;
    auto end_node = 13;
    auto distance = dijkstras(start_node, end_node, file_data);
    std::cout << "Distance from " << start_node << " to " << end_node << ": " << distance << std::endl;

    return 0;
}