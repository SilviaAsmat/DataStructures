/*********************
*Name: Silvia Asmat
*Coding 06
*Purpose:  Create linked list class and methods
**********************/
#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, string* data) {
    bool added = false;
    if (id <= 0 || *data == "") {
        // Invalid data, do nothing
    } else if (head == NULL) {// Empty list
        added = addHead(id, data, NULL);
    } else {
        Node* iterator = head;
        Node* previous = NULL;
        while (iterator != NULL && iterator->data.id < id) {
            // Iterate list to find spot to insert new node
            previous = iterator;
            iterator = iterator->next;
        }
        if (iterator == NULL) {
            // add new tail case
            added = addTail(id, data, previous);
        } else if (iterator->data.id == id) {
            added = false;// Duplicate, do nothing
        } else if (iterator == head) {
            // Add new head
            added = addHead(id, data, iterator);
        } else {
            //add new node to left of iterator
            added = addMiddle(id, data, iterator);
        }//End of if check for valid id and string*
    }
    return added;
}


bool LinkedList::deleteNode(int id) {
    bool deleted = false;
    //head == NULL, do nothing
    if (id <= 0 || head == NULL) {
        // Invalid data or empty list, do nothing
    } else {
        Node* iterator = head;
        Node* previous = NULL;
        bool found = false;
        while(iterator != NULL && !found) {
            if (iterator->data.id == id) {
                found = true;
            } else {
                previous = iterator;
                iterator = iterator->next;
            }
        }
        if (!found) {
            // Invalid data, do nothing
        } else {
            if (iterator == head) {
                deleted = deleteHead(iterator);
            } else {
                // Remove element that's not the head
                if (iterator->next == NULL) {
                    //found id, delete tail
                    previous->next = NULL;
                    delete iterator;
                    deleted = true;
                } else {
                    //found id, delete from middle
                    deleted = deleteMiddle(previous, iterator);
                }
            }
        }
    }
    return deleted;
}

bool LinkedList::getNode(int id, struct Data* data) {
    bool found = false;
    data->id = -1;
    data->data = "";
    Node *iterator = head;
    while(iterator != NULL && found == false) {
        if (iterator->data.id == id) {
            found = true;
            data->id = iterator->data.id;
            data->data = iterator->data.data;
        }
        iterator = iterator->next;
    }
    return found;
}

void LinkedList::printList(bool backward) {
    if (head == NULL) {
        cout << "\tList is empty" << endl;
    } else {
        Node* iterator = head;
        int count = 1;
        if(!backward) {
            while (iterator != NULL) {
                //backward is false, printing forward
                cout << "\t" << count << ": " << iterator->data.id << " : " << iterator->data.data << endl;
                iterator = iterator->next;
                count++;
            }
        } else {
            Node* previous = NULL;
            while (iterator != NULL) {
                //backwards is true, print backwards, find last node
                previous = iterator;
                iterator = iterator->next;
                count++;
            }
            while (previous != NULL) {
                count--;
                cout << "\t" << count << ": " << previous->data.id << " : " << previous->data.data << endl;
                previous = previous->prev;
            }
        }
    }
}

int LinkedList::getCount() {
    int count = 0;
    Node* iterator = head;
    while (iterator != NULL) {
        iterator = iterator->next;
        count++;
    }
    return count;
}

bool LinkedList::clearList() {
    bool cleared;
    Node *iterator = head;
    while(iterator != NULL) {
        delete iterator;
        iterator = iterator->next;
    }
    if(iterator == NULL) {
        cleared = false;
    }
    head = NULL;
    return cleared = true;
}

bool LinkedList::exists(int id) {
    bool exists = false;
    Node* iterator = head;
    while(iterator != NULL && !exists) {
        if (iterator->data.id == id ) {
            exists = true;
        }
        iterator = iterator->next;
    }
    return exists;
}

bool LinkedList::addHead(int id, string* data, Node* iterator) {
    bool added = false;
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    if (head == NULL) {
        // Empty list case
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        added = true;
    } else if (iterator == head) {
        // Add new head
        newNode->prev = NULL;
        newNode->next = iterator;
        iterator->prev = newNode;
        head = newNode;
        added = true;
    }
    return added;
}

bool LinkedList::addTail(int id, string* data, Node* previous) {
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    previous->next = newNode;
    newNode->next = NULL;
    newNode->prev = previous;
    return true;
}

bool LinkedList::addMiddle(int id, string* data, Node* iterator) {
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    iterator->prev->next = newNode;
    newNode->prev = iterator->prev;
    iterator->prev = newNode;
    newNode->next = iterator;
    return true;
}




bool LinkedList::deleteHead(Node* iterator) {
    bool deleted = false;
    // Remove head
    if (iterator->next == NULL) {
        // Deleting single element LL
        delete iterator;
        head = NULL;
        deleted = true;
    } else {
        // Remove head and update head pointer
        iterator->next->prev = NULL;
        head = iterator->next;
        delete iterator;
        deleted = true;
    }
    return deleted;
}

bool LinkedList::deleteMiddle(Node* previous, Node* iterator) {
    iterator->next->prev = previous;
    previous->next = iterator->next;
    delete iterator;
    return true;
}















