//
// Created by amarildo on 2023-04-05.
//


#include "dijkstras.h"

const int NOT_VISITED = 0;
const int VISITED = 1;
const int NOT_CONNECTED = -1;

const double INF = std::numeric_limits<double>::infinity();

double dijkstras(int start, int end, const adjacency_list_t& adj_list) {
    // Initialize the distance vector to infinity
    std::vector<double> dist(adj_list.first.size(), INF);
    // Initialize the handled_nodes set to empty
    std::unordered_set<int> handled_nodes;
    // Initialize the priority queue
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> paths_pq;
    // Push the starting node to the priority queue
    dist[start] = 0;
    paths_pq.push({0, start});

    // While the priority queue is not empty and the end node has not been handled_nodes
    while (!paths_pq.empty()) {
        // Get the node with the smallest distance from the priority queue and mark it as handled_nodes
        const int curr = paths_pq.top().second;
        paths_pq.pop();

        if (handled_nodes.count(curr)) continue;
        handled_nodes.insert(curr);
        // If the current node is the end node, return the distance to it
        if (curr == end){
            return dist[end];
        }
        // For each neighbor of the current node, if the distance to the neighbor is smaller than the current distance,
        // update the distance and push the neighbor to the priority queue with the new distance
        for (const auto& edge : adj_list.second) {
            if (edge.n1 != curr) continue;

            const double new_dist = dist[curr] + edge.weight;
            if (dist[edge.n2] <= new_dist) continue;

            dist[edge.n2] = new_dist;
            paths_pq.push({dist[edge.n2], edge.n2});
        }
    }

    return NOT_CONNECTED;
}




std::vector<int> dijkstras_path(int start, int end, const adjacency_list_t &adj_list) {
    std::vector<double> dist(adj_list.first.size(), INF);
    std::unordered_set<int> visited;

    std::vector<int> prev(adj_list.first.size(), -1);
    prev[start] = start;
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> paths_pq;
    dist[start] = 0;
    paths_pq.push({0, start});
    while (!paths_pq.empty()) {
        const int curr = paths_pq.top().second;
        paths_pq.pop();

        if (visited.count(curr)) continue;
        visited.insert(curr);
        if (curr == end) {
            std::vector<int> path;
            int node = end;
            while (node != start) {
                path.push_back(node);
                node = prev[node];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }
        for (const auto& edge : adj_list.second) {
            if (edge.n1 != curr) continue;

            const double new_dist = dist[curr] + edge.weight;
            if (dist[edge.n2] <= new_dist) continue;

            dist[edge.n2] = new_dist;
            prev[edge.n2] = curr;
            paths_pq.push({dist[edge.n2], edge.n2});
        }
    }

    return {};
}



