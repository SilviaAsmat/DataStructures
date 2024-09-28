/*********************
*Name: Silvia Asmat
*Coding 05
*Purpose:  Create a stack object that will work with a struct data type called Data.
 * stack will be an array of pointers to Data structs
**********************/

// each cpp includes ONLY it's header directly
#include "stack.h"

/*
 * write all your stack methods here
 */

Stack::Stack(int value) {
    size = value;
    this->top = -1;
    
    if (size > 2) {
        stack = new Data*[size]; // dynamically allocates the stack array
    } else {
        stack = new Data*[DEFAULT_SIZE];
    }

}

Stack::~Stack() {
    // deallocate memory
    for (int i = 0; i < top; i++) {
        delete stack[i];
    }
    delete[] stack;
}

bool Stack::push(int value, string *info) {
bool pushed = false;
    if (top < size - 1) {
        if(value > 0 && *info != "") {
            Data *data;
            data = new Data;
            data->id = value;
            data->information = *info;
        
            top++;// increment
            stack[top] = data;
            pushed = true;
        }
    }
    return pushed;
}

bool Stack::pop(Data *myData) {
    bool popped = false;
    
    if (top > -1) {
        myData->id = stack[top]->id;
        myData->information = stack[top]->information;
        delete stack[top];
        top--;
        popped = true;
    } else {
         myData->id = -1;
         myData->information = "";
    }
    return popped;
}

bool Stack::peek(Data *myData) {
    bool peeked = false;
    
    if (top > -1) {
        myData->id = stack[top]->id;
        myData->information = stack[top]->information;
        peeked = true;
    } else {
         myData->id = -1;
         myData->information = "";
     }
    return peeked;
}

bool Stack::isEmpty() {
    return top < 0;
}

void Stack::dumpStack() {
    cout << "dumping whole stack..." << endl;
    if (!isEmpty()) {
        for (int i = top+1; i >= 0; i--) {
            cout << stack[i] << endl;
        }
        top = -1;
    } else {
       cout << "\tstack is empty" << endl;
    }
    cout << endl;
}

