/*********************
Name: Arjun Devireddy
Coding 04
Purpose: This program creates the functions that make up the Stack ADT
**********************/

#include "stack.h"
Stack::Stack(){
    top = -1;
}


bool Stack::push(int p){
    if(top >= MAX - 1){
        return false;
    }
    stack[++top] = p;
    return true;
    
}

bool Stack::isEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}

int Stack::pop(){
    if(top == -1){
        throw -1;
    }
    return stack[top--];

}

int Stack::peek(){
    if(top == -1){
        throw -1;
    }
    return stack[top];

}
