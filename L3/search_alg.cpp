//
// Created by amarildo on 2023-04-30.
//
#include <iostream>
#include "search_alg.h"


int linear_search(std::vector<bool> &vect, int target) {
    for (int i = 2; i < vect.size(); i++) {
        if (vect[i] == true && i == target)
            return i;
    }
    return -1;
}

int binary_search_int(std::vector<int> &vect, int target) {
    int low = 0;
    int high = vect.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (vect[mid] == target) {
            return mid;
        } else if (vect[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int linear_search_int(std::vector<int> &vect, int target) {
    for (int i = 2; i < vect.size(); i++) {
        if (vect[i] == target)
            return i;
    }
    return -1;
}


int TreeNode::binary_search(TreeNode *root, int target) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (target == current->data) {
            return current->data;
        } else if (target < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return -1;
}

void TreeNode::insert(int &i) {
    if (i < this->data) {
        if (this->left == nullptr) {
            this->left = new TreeNode();
            this->left->data = i;
            this->left->parent = this;
            this->left->left = nullptr;
            this->left->right = nullptr;
        } else {
            this->left->insert(i);
        }
    } else {
        if (this->right == nullptr) {
            this->right = new TreeNode();
            this->right->data = i;
            this->right->parent = this;
            this->right->left = nullptr;
            this->right->right = nullptr;
        } else {
            this->right->insert(i);
        }
    }

}

TreeNode::TreeNode(std::vector<int> &vect) {
    if (vect.empty()) {
        this->data = 0;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        return;
    }

    this->data = vect[0];
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;

    for (unsigned int i = 1; i < vect.size(); i++) {
        this->insert(vect[i]);
    }

}


