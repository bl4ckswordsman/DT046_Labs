//
// Created by amra2101 on 2023-05-15.
//

#ifndef DT046G_L3_HASH_TABLE_H
#define DT046G_L3_HASH_TABLE_H

#include <vector>

const int reserved_size = 100000;

struct Hash_node {
    int data;
    Hash_node* next;
};

std::vector<Hash_node*> hash_table(reserved_size);

#endif //DT046G_L3_HASH_TABLE_H
