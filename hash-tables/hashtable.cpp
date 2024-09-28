/*********************
*Name: Silvia Asmat
*Coding 07
*Purpose:  Create hashtable of linked list using separate chaining
**********************/
#include "hashtable.h"

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0;i < HASHTABLESIZE; i++) {
        hashTable[i] = LinkedList();
    }
}
//Private Method
int Hashtable::hash(int id) {
    // guarantees a position between 0 and HASHTABLESIZE - 1
    return id % HASHTABLESIZE;
}

/*Public Methods*/
bool Hashtable::insertEntry(int id, string& data) {
    bool inserted;
    if (id > 0 && data != "") {
        int position = hash(id);
        inserted = hashTable[position].addNode(id, data);
        if (inserted) {
            count++;
        }
    } else {
        inserted = false;
    }
    return inserted;
}

string Hashtable::getData(int id) {
    string retData = "";
    if(id > 0) {
        int position = hash(id);
        Data* data = new Data;
        bool found = hashTable[position].getNode(id, data);
        if (found) {
            retData = data->data;
        }
        delete data;
    }
    return retData;
}

bool Hashtable::removeEntry(int id) {
    bool removed;
    int position = hash(id);
    removed = hashTable[position].deleteNode(id);
    if (removed) {
        count--;
    } else {
        removed = false;
    }
    return removed;
}

void Hashtable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        cout << "Entry " << i << " :";
        hashTable[i].printList();
    }
}

int Hashtable::getCount() {
    return count;
}
