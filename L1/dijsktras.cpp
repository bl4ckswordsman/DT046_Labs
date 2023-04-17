//
// Created by amarildo on 2023-04-05.
//


#include "dijkstras.h"

const int NOT_VISITED = 0;
const int VISITED = 1;
const int NOT_CONNECTED = -1;



double dijkstras(int start, int end, const std::vector<std::vector<std::pair<int, double>>> &adj_list) {
    std::vector<double> dist(adj_list.size(), std::numeric_limits<double>::max());
    std::vector<int> visited(adj_list.size(), NOT_VISITED);
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();

        if (visited[curr] == NOT_VISITED) {
            visited[curr] = VISITED;

            for (const auto &edge: adj_list[curr]) {
                if (edge.second != NOT_CONNECTED) {
                    if (dist[edge.first] > dist[curr] + edge.second) {
                        dist[edge.first] = dist[curr] + edge.second;
                        pq.push({dist[edge.first], edge.first});
                    }
                }
            }
        }
    }


    return dist[end];
}
