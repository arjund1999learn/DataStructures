/*
 Name: Arjun Devireddy
 Coding 05
 Purpose: This program creates a stack ADT that dynamically allocates size.
*/

// each cpp includes ONLY it's header directly
#include "stack.h"

/*
 * write all your stack methods here
 */
Stack::Stack(int s){
    top = -1;
    size = 10;
    if(s >= 2){
        size = s;
    }
    stack = new Data* [size];
     
}


bool Stack::push(int p, string& s){
    bool pushed = false;
    if(p > 0 && !s.empty() && top < (size -1)){
        stack[++top] = new Data;
        stack[top]->id = p;
        stack[top]->information = s;
        pushed = true;
    }
    return pushed;
}

bool Stack::isEmpty(){
    return top == -1;

}

bool Stack::pop(Data &d){
    bool popped = false;
    if(top != -1){
        d.id = stack[top]->id;
        d.information = stack[top]->information;
        delete stack[top--];
        popped = true;
    }
    else{
        d.id = -1;
        d.information = "";
    }
    return popped;

}

bool Stack::peek(Data &d){
    bool peeked = false;
    if(top != -1){
        d.id = stack[top]->id;
        d.information = stack[top]->information;
        peeked = true;
    }
    else{
        d.id = -1;
        d.information = "";
    }
    return peeked;

}

Stack::~Stack(){
    for(int i = 0; i <= top; i++){
        delete stack[i];
    }
    delete [] stack;
}