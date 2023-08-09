/* 
 Name: Arjun Devireddy
 Coding 07
 Purpose: This program holds the declarations for hashtable.cpp
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "linkedlist.h"
#define HASHTABLESIZE 15

class HashTable{

public:
    HashTable();
    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();


private:
    int hash(int);
    int count;
    LinkedList** table;

};
#endif //HASHTABLE_H