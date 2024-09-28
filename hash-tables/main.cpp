/*********************
*Name: Silvia Asmat
*Coding 07
*Purpose:  Create hashtable of linked list using separate chaining
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    Hashtable hashTable = Hashtable();
    // show it is empty by calling getCount and printTable
    int count;
    count = hashTable.getCount();
    
    cout << "count: " << count << endl;
    hashTable.printTable();
    

    // try and put ALL the test data into the table and show what happens
    cout << "------------------------------------" << endl;
    cout << "ADDING ALL TEST DATA" << endl;
    cout << "------------------------------------" << endl;
    bool inserted = false;
    for (int i = 0; i < testdatasize; i++) {
        inserted = hashTable.insertEntry(ids[i], strs[i]);
        count = hashTable.getCount();
        cout << "inserted: " << ids[i] << " : " << strs[i] << "\tcount: " << count << endl;
    }
    
    hashTable.printTable();

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.
     
    //remove all elements in hashtable
    cout << "------------------------------------" << endl;
    cout << "EMPTYING HASHTABLE COMPLETELY" << endl;
    cout << "------------------------------------" << endl;
    bool removed = false;
    for (int i = 0; i < testdatasize; i++) {
        
        removed = hashTable.removeEntry(ids[i]);
        cout << "\nremoving: " << ids[i] << " : " << strs[i] << "..." ;
        if (removed) {
            cout << " removed";
        } else {
            cout << " not found";
        }
        int num = hashTable.getCount();
        cout << "\tcount: " << num << endl;
    }
    hashTable.printTable();
    
    //fill halfway
    cout << "------------------------------------" << endl;
    cout << "FILLING HASHTABLE HALFWAY" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < HASHTABLESIZE/HALF; i++) {
        int arrIndex = i%testdatasize;
        inserted = hashTable.insertEntry(ids[arrIndex], strs[arrIndex]);
        count = hashTable.getCount();
        cout << "inserted: " << ids[arrIndex] << " : " << strs[arrIndex] << "\tcount: " << count << endl;
    }
    hashTable.printTable();
    
    //find data
    cout << "------------------------------------" << endl;
    cout << "FINDING HASHTABLE DATA" << endl;
    cout << "------------------------------------" << endl;
    string findData = "";
    for (int i = 0; i < count; i++) {
        findData = hashTable.getData(ids[i]);
        cout << "found data: id:" << ids[i] << " data: " << findData << endl;
    }
    //overfill
    cout << "------------------------------------" << endl;
    cout << "OVERFILLING HASHTABLE " << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < HASHTABLESIZE*MULTIPLIER; i++) {
        int arrIndex = i%testdatasize;
        inserted = hashTable.insertEntry(ids[arrIndex], strs[arrIndex]);
        count = hashTable.getCount();
        cout << "inserted: " << ids[arrIndex] << " : " << strs[arrIndex] << "\tcount: " << count << endl;
    }
    hashTable.printTable();
    //try empty more than amount of existing elements
    cout << "------------------------------------" << endl;
    cout << "OVER EMPTYING HASHTABLE" << endl;
    cout << "------------------------------------" << endl;
    removed = false;
    for (int i = 0; i < testdatasize*BUFFERSIZE; i++) {
        int arrIndex = i%testdatasize;
        removed = hashTable.removeEntry(ids[arrIndex]);
        cout << "\nremoving: " << ids[arrIndex] << " : " << strs[arrIndex] << "..." ;
        if (removed) {
            cout << " removed";
        } else {
            cout << " not found";
        }
        cout << endl;
    }
    hashTable.printTable();
     
    return 0;
}
