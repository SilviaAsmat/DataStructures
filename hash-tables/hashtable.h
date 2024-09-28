/*********************
*Name: Silvia Asmat
*Coding 07
*Purpose:  Create hashtable of linked list using separate chaining
**********************/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include "data.h"
#include "linkedlist.h"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class Hashtable {

public:
    Hashtable();
    
    bool insertEntry(int, string&);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:

    int hash(int);
    int count;
    LinkedList hashTable[HASHTABLESIZE];
};

#endif // HASHTABLE_HASHTABLE_H 
