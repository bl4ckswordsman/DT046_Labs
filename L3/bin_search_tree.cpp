//
// Created by amarildo on 2023-05-13.
//

#include "bin_search_tree.h"

//Tree_node* root;

void insert(Tree_node*& node, int value) {
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

/*int binary_search_tree(std::vector<int> &vect, int target) {
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
}*/

//V2
int binary_search_tree(std::vector<int>& vect, int target) {
    Tree_node* root = nullptr;
    build_tree(vect, root);
    int result = binary_search_tree(root, target);
    delete_tree(root);
    return result;
}

/*void build_tree(std::vector<int> &vect) {
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

}*/

//V2
void build_tree(std::vector<int>& vect, Tree_node*& root) {
    for (int value : vect) {
        insert(root, value);
    }
}

void build_tree3(std::vector<int>& vect, Tree_node*& root) {
    //std::sort(vect.begin(), vect.end());  // Sort the input vector

    int n = vect.size();
    int search_set_size = n * n - 2;

    // Create a search set of size N^2 - 2
    std::vector<int> search_set(search_set_size);
    int mid_index = search_set_size / 2;

    // Insert the sorted vector into the search set, excluding the middle element
    int search_set_index = 0;
    for (int i = 0; i < search_set_size; i++) {
        if (search_set_index == mid_index) {
            search_set_index++;  // Skip the middle element
        }
        search_set[i] = vect[search_set_index++];
    }

    // Insert the middle element as the root of the tree
    root = new Tree_node;
    root->data = vect[mid_index];
    root->left = nullptr;
    root->right = nullptr;

    // Insert the remaining elements into the tree
    for (int i = 0; i < search_set_size; i++) {
        insert(root, search_set[i]);
    }
}



/*void build_tree2(std::vector<int> &vect) {
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
}*/


int binary_search_tree(Tree_node *root, int target) {
    if (root == nullptr) {
        return -1;  // Target not found
    }

    if (root->data == target) {
        return root->data;
    } else if (target < root->data) {
        return binary_search_tree(root->left, target);
    } else {
        return binary_search_tree(root->right, target);
    }
}

void delete_tree(Tree_node *node) {
    if (node == nullptr) {
        return;
    }

    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}
