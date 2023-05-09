//
// Created by amarildo on 2023-04-30.
//

#include <vector>

#ifndef L3_SEARCH_ALG_H
#define L3_SEARCH_ALG_H

#endif //L3_SEARCH_ALG_H


int linear_search(std::vector<bool>& vect, int target);

int linear_search_int(std::vector<int>& vect, int target);

struct TreeNode {
    int data;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        this->data = 0;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~TreeNode() {
        delete this->left;
        delete this->right;
    }

    void insert(int &i);

    TreeNode(std::vector<int>& vect);

    int binary_search(TreeNode* root, int target);

};

int binary_search_int(std::vector<int>& vect, int target);




