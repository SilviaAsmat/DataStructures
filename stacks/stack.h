/*********************
*Name: Silvia Asmat
*Coding 05
*Purpose:  Create a stack object that will work with a struct data type called Data.
 * stack will be an array of pointers to Data structs
**********************/
#ifndef STACK_H
#define STACK_H
#define DEFAULT_SIZE 10

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#include <iostream>
using std::endl;
using std::cout;
using std::string;

class Stack {

public:

    /*
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    Stack(int); // Constructor
    ~Stack(); // Destructor
    bool pop(struct Data*);
    bool peek(struct Data*);
    bool push (int, string*);
    bool isEmpty();
    void dumpStack();
    
private:

    /*
     * write all your private method prototypes here
     */

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **stack;
    // notice stack is a pointer to a pointer. That means if you do
    // a single array allocation, you will get an array of pointers
};

#endif //STACK_H
