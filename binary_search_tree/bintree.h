/*****************
*Name: Silvia Asmat
*Coding 08
*Purpose:  Create a Binary Search Tree class working with a struct Data and a struct Node
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include <string>
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class BinTree {
public:
    BinTree();
    ~BinTree();
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();
    /*Following methods will have private overloads for recursion*/
    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:
    DataNode *root;
    int count;
    DataNode* minValueNode(DataNode*);
    /*Following methods will have public methods that call them*/
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
    
};
#endif /* BINTREE_BINTREE_H */
