/*********************
*Name: Silvia Asmat
*Coding 05
*Purpose:  Create a stack object that will work with a struct data type called Data.
 * stack will be an array of pointers to Data structs
**********************/
#include "main.h"

int main(int argc, char *argv[]) {
    // here for the rand_string() function
    // if you don't use it, get rid of this
    srand(time(NULL));

    char *argument = argv[1];
    bool isInt = true;
    for (int i = 0; i < strlen(argument); i++) {
        if(isdigit(argument[i])) {
        } else {
            isInt = false;
        }
    }
    
    bool hasTwoArguments = argc == 2;
    bool hasValidIntArgument = hasTwoArguments && isInt;
    if(hasValidIntArgument) {
        int size = std::atoi(argv[1]);
        Stack stack(size);
        Data data;
        cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
        cout << "=====================================================" << endl;
        
        // testing isEmpty() on empty stack
        if (stack.isEmpty()) {
            cout << "TEST PASSED: stack is empty" << endl;
        } else {
            cout << "TEST FAILED: stack is NOT empty" << endl;
        }
            
        // testing peek() and pop() on empty stack
        if(stack.peek(&data)){
            cout << "TEST FAILED: peeked: "<< endl;
        } else {
            cout << "TEST PASSED: peek underflow error: stack is empty" << endl;
        }
        
        if(stack.pop(&data)) {
            cout << "TEST FAILED: popped: " << endl;
        } else {
            cout << "TEST PASSED: pop underflow error: stack is empty" << endl;
        }
        cout << endl;
    
        cout << "Testing fill operations." << endl;
        cout << "=====================================================" << endl;
        // testing filling the stack and overflow
        cout << "Filling stack..." << endl;
    
    
        for (int i = 0; i < size*MULTIPLIER; i++) {
            int value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number
            string strtemp;
            rand_string(&strtemp);
            if (stack.push(value, &strtemp)) {
                cout << "TEST PASSED: pushed id : " << value << "  info: " << strtemp << endl;
            } else {
                cout << "TEST PASSED: push overflow or invalid data error: not pushed: id: " << value << "  info: " << strtemp << endl;
            }
        }
        cout << endl;
        
        cout << "Testing full stack." << endl;
        cout << "=====================================================" << endl;
        // fills stack
        for(int i = 0; i < size+1; i++) {
            int value = 2;
            string strtemp = "abcd";
            stack.push(value, &strtemp);
        }
        // testing isEmpty() on filled stack
        if (stack.isEmpty()) {
            cout << "TEST FAILED: stack is empty" << endl;
        } else {
            cout << "TEST PASSED: stack is NOT empty" << endl;
        }
        cout << endl;
        
        // testing peek() and pop() on filled stack
        if(stack.peek(&data)){
            cout << "TEST PASSED: peeked: " << endl;
        } else {
            cout << "TEST FAILED: peek underflow error: stack is empty" << endl;
        }
        
        if(stack.pop(&data)){
            cout << "TEST PASSED: popped: " << endl;
        } else {
            cout << "TEST FAILED: pop underflow error: stack is empty" << endl;
        }
        cout << endl;
        
        cout << "Dumping stack..." << endl;
        cout << "=====================================================" << endl;
        stack.dumpStack();
        
        
        cout << "Testing peek and pop on whole stack, and emptying stack..." << endl;
        cout << "=====================================================" << endl;

            // testing popping and peeking whole stack
        for (int i = 0; i < MULTIPLIER*size; i++) {
            if(stack.peek(&data)) {
                cout << "TEST FAILED: peeked: " << endl;
            } else {
                cout << "TEST PASSED: peek underflow error: stack is empty" << endl;
            }
            if(stack.pop(&data)) {
                cout << "TEST FAILED: popped: " << endl;
            } else {
                cout << "TEST PASSED: pop underflow error: stack is empty" << endl;
            }
        }
        cout << endl;
        
        
        cout << "Dumping stack..." << endl;
        cout << "=====================================================" << endl;
        stack.dumpStack();
        
        // testing isEmpty() on empty stack
        if (stack.isEmpty()) {
            cout << "TEST PASSED: stack is empty" << endl;
        } else {
            cout << "TEST FAILED: stack is NOT empty" << endl;
        }

        // testing peek() and pop() on empty stack
        if(stack.peek(&data)){
            cout << "TEST FAILED: peeked: " << endl;
        } else {
            cout << "TEST PASSED: peek underflow error: stack is empty" << endl;
        }
            
        if(stack.pop(&data)){
            cout << "TEST FAILED: popped: " << endl;
        } else {
            cout << "TEST PASSED: pop underflow error: stack is empty" << endl;
        }
        cout << endl;
        
        /************************************************
          ******** RANDOM TESTS ***************************
          ************************************************/
        
        cout << "Random testing..." << endl;
        cout << "============================================================" << endl;
        // clearing stack to start
        while(!stack.isEmpty()){
            stack.pop(&data);
        }

        // filling the stack half way with random numbers to begin random tests
        for (int i = 0; i< int(size / 2); i++) {
            int value = rand() % 2 + 1;
            string strtemp;
            rand_string(&strtemp);
            if (stack.push(value, &strtemp)) {
                cout << "TEST PASSED: pushed: id: " << value << "  string: " << strtemp << endl;
            } else {
                cout << "TEST PASSED: overflow / invalid data error: id: " << value << "    string: " << strtemp << " not pushed" << endl;
            }
        }
        
        int value;
        int choice = rand() % CHOICES + 1;
        for (int i = 0; i < size*RANDOM_MULTIPLIER; i++) {
            string strtemp;
            rand_string(&strtemp);
            switch (choice) {
                case 1:
                case 2:
                    // push
                    value = rand()%2 ? -(i + 1) : i+1;
                    if (stack.push(value, &strtemp)) {
                        cout << "pushed: id: " << value << "   string: " << strtemp << endl;
                    } else {
                        cout << "overflow / invalid data error: id: " << value << "    string: " << strtemp << " not pushed" << endl;
                    }
                    break;
                case 3:
                case 4:
                    // pop
                    if(stack.pop(&data)) {
                        cout << "popped: id: " << data.id <<"    string: " << data.information << endl;
                    } else {
                        cout << "pop underflow error: stack is empty" << endl;
                    }
                    break;
                case 5:
                    // peek
                    if(stack.peek(&data)){
                        cout << "peeked: " << data.id << "  string: " << data.information << endl;
                    } else {
                        cout << "peek underflow error: stack is empty" << endl;
                    }
                    break;
                case 6:
                    // isempty
                    if (stack.isEmpty()) {
                        cout << "stack is empty" << endl;
                    } else {
                        cout << "stack is NOT empty" << endl;
                    }
                    break;
            }
            choice = rand() % CHOICES + 1;
        }
        cout << endl;

        // this is a programmer debug routine used for debugging during development
        // and is normally not used for final testing but is shown here for demonstration
        cout << "Dumping stack..." << endl;
        cout << "=====================================================" << endl;
        stack.dumpStack();
        
       cout << "Testing complete." << endl;

    } else { // when hasValidIntArgument is false
    cout << "Invalid arguments, one integer argument only" << endl;
    }
    
    return 0;
}
