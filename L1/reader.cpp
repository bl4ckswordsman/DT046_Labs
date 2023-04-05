// reader.cpp:
//
// Created by amarildo on 2023-04-02.
//

#include "reader.h"

#include<fstream>
#include<string>
#include<map>


enum token{
    COMMENT, // The line is a comment
    META, // The line is metadata
    EDGE, // The line describes an edge
    END_OF_FILE // End of the file has been reached
};

// Determine the type of the next line in the input stream
token get_line_type(std::istream& is){
    switch(is.peek()){
        case std::istream::traits_type::eof(): return END_OF_FILE;
        case '#': return COMMENT;
        case 'M': return META;
    };
    return EDGE;
}

// A map to store metadata
meta_t meta;

// Read an edge from the input stream
edge read_edge(std::istream& is){
    edge e;
    is >> e.n1 >> e.n2 >> e.weight;
    std::getline(is, e.description);
    return e;
}

// Read metadata from the input stream and store it in the meta map
void read_meta(std::istream& is){
    char discard;
    node_id_t vertex_id;
    std::string name;
    is >> discard >> vertex_id;
    std::getline(is, name);
    meta[vertex_id] = name;
}

// Parse a file and return an adjacency list
adjacency_list_t parse_file(std::string filename){
    std::ifstream in(filename);
    token l;
    edge_list_t edge_list;
    while((l = get_line_type(in)) != END_OF_FILE){
        edge e;
        switch(l){
            case token::EDGE:
                e = read_edge(in);
                edge_list.push_back(e);
                break;
            case token::META:
                read_meta(in);
                break;
            default:
                std::string comment;
                std::getline(in, comment);
        }
    }
    return adjacency_list_t{meta, edge_list};
}
