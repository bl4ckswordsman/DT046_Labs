//
// Created by amarildo on 2023-05-13.
//

#ifndef DT046G_L3_BIN_SEARCH_TREE_H
#define DT046G_L3_BIN_SEARCH_TREE_H

#include <vector>

struct Tree_node {
    int data;
    Tree_node* left;
    Tree_node* right;
};


void insert(Tree_node* node, int value);

int binary_search_tree(std::vector<int>& vect, int target);

void build_tree(std::vector<int>& vect);



#endif //DT046G_L3_BIN_SEARCH_TREE_H
