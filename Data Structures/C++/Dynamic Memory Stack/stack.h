/*
 Name: Arjun Devireddy
 Coding 05
 Purpose: This program holds the declarations for stack.cpp
*/

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
class Stack {

public:
    bool push(int, string&);
    bool pop(Data &d);
    bool peek(Data &d);
    bool isEmpty();
    Stack(int);
    ~Stack();
    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    
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
