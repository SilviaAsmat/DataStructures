/*********************
*Name: Silvia Asmat
*Coding 07
*Purpose:  Create hashtable of linked list using separate chaining
**********************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */

