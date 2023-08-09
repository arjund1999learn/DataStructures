/*********************
Name: Arjun Devireddy
Coding 04
Purpose: This program holds the declarations for stack.cpp
**********************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define MAX 10

class Stack{

    public:
    Stack();

    bool push(int);
    bool isEmpty();
    int pop();
    int peek();
    void dumpstack();
    

protected:
    int top; 
    int stack[MAX];

};
#endif //STACK_STACK_H


