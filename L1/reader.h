// reader.h:
//
// Created by amarildo on 2023-04-02.
//

#ifndef DOA_LABB1_READER_H
#define DOA_LABB1_READER_H

#include<istream>
#include<map>
#include<vector>


using node_id_t = int;
using weight_t = double;
using meta_t = std::map<node_id_t, std::string>;


struct edge{
    node_id_t n1;
    node_id_t n2;
    weight_t weight;
    std::string description;
};

using edge_list_t = std::vector<edge>;

using adjacency_list_t = std::pair<meta_t, edge_list_t>;

adjacency_list_t parse_file(std::string filename);

#endif //DOA_LABB1_READER_H
