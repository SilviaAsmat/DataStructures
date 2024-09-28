/*****************
*Name: Silvia Asmat
*Coding 08
*Purpose:  Create a Binary Search Tree class working with a struct Data and a struct Node
**********************/
#include "bintree.h"

/******************PUBLIC METHODS******************/
BinTree::BinTree() {
    root = NULL;
    count = 0;
}

BinTree::~BinTree() {
   clear();
}

bool BinTree::isEmpty() {
    bool empty = true;
    if(root) {
        empty = false;
    }
    return empty;
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data* data) {
    bool found = false;
    if (root) { //Tree is not empty
        data->id = root->data.id;
        data->information = root->data.information;
        found = true;
    } else { //Tree is empty
        data->id = -1;
        data->information = "";
    }
    return found;
}

void BinTree::displayTree() {
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;
    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder(root);
    cout << "\nIn-Order Traversal" << endl;
    displayInOrder(root);
    cout << "\nPost-Order Traversal" << endl;
    displayPostOrder(root);
    cout << "==============================================" << endl;
}

/****************Following public methods will have private overloads for recursion****************/

void BinTree::clear() {
    clear(root);
    root = NULL;
    count = 0;
}

bool BinTree::addNode(int id, const string* data) {
    bool added = false;
    if (id > 0 && *data != "") {
        DataNode* newDataNode = new DataNode;
        newDataNode->left = NULL;
        newDataNode->right = NULL;
        newDataNode->data.id = id;
        newDataNode->data.information = *data;
        added = addNode(newDataNode, &root);//syntax issues
    }
    if (added) {
        count++;
    }
    return added;
}

bool BinTree::removeNode(int id) {
    int tempCount = count;
    root = removeNode(id, root);
    return count < tempCount;
}

bool BinTree::getNode(Data* data, int id) {
    bool found = false;
    if (id > 0) {
        found = getNode(data, id, root);
    }
    return found;
}

bool BinTree::contains(int id) {
    bool found = false;
    if (id > 0) {
        found = contains(id, root);
    }
    return found;
}
int BinTree::getHeight() {
    int height = 0;
    height = getHeight(root);
    return height;
}
void BinTree::displayPreOrder() {
    displayPreOrder(root);
}
void BinTree::displayPostOrder() {
    displayPostOrder(root);
}
void BinTree::displayInOrder() {
    displayInOrder(root);
}

/******************PRIVATE METHODS******************/
void BinTree::clear(DataNode* tempRoot) {
    if (tempRoot) {
        clear(tempRoot->left);
        clear(tempRoot->right);
        tempRoot->left = NULL;
        tempRoot->right = NULL;
        delete tempRoot;
    }
}

bool BinTree::addNode(DataNode* newDataNode, DataNode** tempRoot) {
    bool added = false;
    if(*tempRoot) {
        if(newDataNode->data.id < (*tempRoot)->data.id) {
            added = addNode(newDataNode, &(*tempRoot)->left);
        } else if (newDataNode->data.id > (*tempRoot)->data.id) {
            added = addNode(newDataNode, &(*tempRoot)->right);
        }
    } else {
        *tempRoot = newDataNode;
        added = true;
    }
    return added;
}

DataNode* BinTree::removeNode(int id, DataNode *tempRoot) {
    if(tempRoot) {
        if(id < tempRoot->data.id) {
            tempRoot->left = removeNode(id, tempRoot->left);
        }
        else if (id > tempRoot->data.id){
            tempRoot->right = removeNode(id, tempRoot->right);
        }
        else {
            DataNode *temp = new DataNode;
            if (tempRoot->left == NULL) {
                temp = tempRoot->right;
                delete tempRoot;
                tempRoot = temp;
                count--;
            } else if (tempRoot->right == NULL) {
                temp = tempRoot->left;
                delete tempRoot;
                tempRoot = temp;
                count--;
            } else {
                temp = minValueNode(tempRoot->right);
                tempRoot->data.id = temp->data.id;
                tempRoot->data.information = temp->data.information;
                tempRoot->right = removeNode(temp->data.id, tempRoot->right);
            }
        }
    }
    return tempRoot;
}

DataNode* BinTree::minValueNode(DataNode *tempRoot) {
    DataNode* current = tempRoot;
    while (current && current->left != NULL) {
    current = current->left;
    }
    return current;
}

bool BinTree::contains(int id, DataNode *tempRoot) {
    bool exists = false;
    if(tempRoot) {
        if (id == tempRoot->data.id) {
            exists = true;
        } else {
            if (id < tempRoot->data.id) {
                exists = contains(id, tempRoot->left);
            } else if (id > tempRoot->data.id) {
                exists = contains(id, tempRoot->right);
            }
        }
    } else {
        //do nothing, exists is false
    }
    return exists;
}

bool BinTree::getNode(Data* tempData, int id, DataNode* tempRoot) {
    bool found = false;
    if (tempRoot) {
        if (tempRoot->data.id == id) {
            found = true;
            tempData->id = tempRoot->data.id;
            tempData->information = tempRoot->data.information;
        } else if (tempRoot->data.id > id) {
            found = getNode(tempData, id, tempRoot->left);
        } else if (tempRoot->data.id < id) {
            found = getNode(tempData, id, tempRoot->right);
        }
    }
    return found;
}

int BinTree::getHeight(DataNode *tempRoot) {
    int height = 0;
    int leftHeight = 0;
    int rightHeight = 0;
    if (tempRoot) {
        leftHeight = getHeight(tempRoot->left);
        rightHeight = getHeight(tempRoot->right);
        height = std::max(leftHeight, rightHeight)+1;
    }
    return height;
}

void BinTree::displayPreOrder(DataNode *tempRoot) {
    if (tempRoot) {
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
        if (tempRoot->left) {
            displayInOrder(tempRoot->left);
        }
        if (tempRoot->right) {
            displayInOrder(tempRoot->right);
        }
    }
}

void BinTree::displayPostOrder(DataNode *tempRoot) {
    if (tempRoot) {
        if (tempRoot->left) {
            displayInOrder(tempRoot->left);
        }
        if (tempRoot->right) {
            displayInOrder(tempRoot->right);
        }
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
    }
}

void BinTree::displayInOrder(DataNode *tempRoot) {
    if (tempRoot) {
        if (tempRoot->left) {
            displayInOrder(tempRoot->left);
        }
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
        if (tempRoot->right) {
            displayInOrder(tempRoot->right);
        }
    }
}
