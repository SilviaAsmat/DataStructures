/*********************
*Name: Silvia Asmat
*Coding 06
*Purpose:  Create linked list class and methods
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "data.h"
using std::cout;
using std::endl;
using std::string;


// this is the actual node with it's header (the pointers) and it's payload (Data)
class LinkedList {
    
public:
        
    LinkedList(); // Constructor
    ~LinkedList(); // Deconstructor
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
    
private:
    Node *head;
    
    bool addHead(int, string*, Node*);
    bool addTail(int, string*, Node*);
    bool addMiddle(int, string*, Node*);
    bool deleteHead(Node*);
    
    bool deleteMiddle(Node*, Node*);
};

#endif //LINKEDLIST_H
