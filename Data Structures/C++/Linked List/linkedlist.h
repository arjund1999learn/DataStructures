/*
 Name: Arjun Devireddy
 Coding 06
 Purpose: This program holds the declarations for linkedlist.cpp
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include <iostream>
using std::cout;
using std::endl;

class LinkedList{

public:
    LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);

private:
    Node *head;
    void deleteHead();
    void addHead(int, string*, bool*);
    void addTail(int, string*, bool*, Node*);
    void addGeneral(int, string*,bool*, Node*);
    Node* createNode(int, string*);
};

#endif //LINKEDLIST_H