//
// Created by amarildo on 2023-05-13.
//

#include "bin_search_tree.h"

Tree_node root;

void insert(Tree_node *node, int value) {
    if (node == nullptr) {
        node = new Tree_node;
        node->data = value;
        node->left = nullptr;
        node->right = nullptr;
        return;
    }

    if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

int binary_search_tree(std::vector<int> &vect, int target) {
    Tree_node* current = &root;
    while (current != nullptr) {
        if (current->data == target) {
            return target;
        } else if (current->data > target) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return -1;
}

void build_tree(std::vector<int> &vect) {
    root.data = vect[0];
    root.left = nullptr;
    root.right = nullptr;
    for (int i = 1; i < vect.size(); i++) {
        Tree_node* current = &root;
        while (true) {
            if (vect[i] < current->data) {
                if (current->left == nullptr) {
                    current->left = new Tree_node;
                    current->left->data = vect[i];
                    current->left->left = nullptr;
                    current->left->right = nullptr;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = new Tree_node;
                    current->right->data = vect[i];
                    current->right->left = nullptr;
                    current->right->right = nullptr;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

}



void build_tree2(std::vector<int> &vect) {
    root.data = vect[(vect.size() - 1) / 2];
    root.left = nullptr;
    root.right = nullptr;

    // Construct the left subtree
    if ((vect.size() - 1) / 2 > 0) {
        std::vector<int> left_data(vect.begin(), vect.begin() + (vect.size() - 1) / 2);
        build_tree(left_data);
        root.left = new Tree_node;
        root.left = &root;
    }

    // Construct the right subtree
    if ((vect.size() - 1) / 2 < vect.size() - 1) {
        std::vector<int> right_data(vect.begin() + (vect.size() - 1) / 2 + 1, vect.end());
        build_tree(right_data);
        root.right = new Tree_node;
        root.right = &root;
    }
}


