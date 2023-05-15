//
// Created by amra2101 on 2023-05-15.
//

#ifndef DT046G_L3_HASH_TABLE_H
#define DT046G_L3_HASH_TABLE_H

#include <vector>

const int reserved_size = 100'000;

struct Hash_node {
    int data;
    Hash_node* next;
};



void insert_into_hash_table(Hash_node*& node, int value);
void insert_into_hash_table(int value);

int hash_function(int value);

int search_hash_table(int value);

int vect_to_hash_table(std::vector<int>& vect);

#endif //DT046G_L3_HASH_TABLE_H
