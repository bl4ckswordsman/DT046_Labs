//
// Created by amra2101 on 2023-05-15.
//

#include "hash_table.h"

std::vector<Hash_node*> hash_table(reserved_size);

void insert_into_hash_table(Hash_node *&node, int value) {
    int size = hash_table.size();
    int hash = hash_function(value);
    auto* new_node = new Hash_node{value, nullptr};
    if (hash_table[hash] == nullptr) {
        hash_table[hash] = new_node;
    } else {
        Hash_node* current = hash_table[hash];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_into_hash_table(int value) {
    int size = hash_table.size();
    int hash = hash_function(value);
    auto* new_node = new Hash_node{value, nullptr};
    if (hash_table[hash] == nullptr) {
        hash_table[hash] = new_node;
    } else {
        Hash_node* current = hash_table[hash];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}


int hash_function(int value) {
    return value % hash_table.size();
}





int search_hash_table(int value) {
    int hash = hash_function(value);
    Hash_node* current = hash_table[hash];
    while (current != nullptr) {
        if (current->data == value) {
            return value;
        }
        current = current->next;
    }
    return -1;
}

int vect_to_hash_table(std::vector<int> &vect) {
    for (int i : vect) {
        insert_into_hash_table(i);
    }
    return 0;
}
