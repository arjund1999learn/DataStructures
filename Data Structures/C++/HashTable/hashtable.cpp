/* 
 Name: Arjun Devireddy
 Coding 07
 Purpose: This program creates an hashtable using an array of pointers to linked lists
 */

#include "hashtable.h"

HashTable::HashTable(){
    table = new LinkedList* [HASHTABLESIZE];
    for(int i = 0; i < HASHTABLESIZE; ++i) {
        table[i] = new LinkedList;
    }
    count = 0;
}

bool HashTable::insertEntry(int id, string* text){
    bool inserted = table[hash(id)]->addNode(id, text);
    count = inserted ? ++count : count;
    return inserted;
}

string HashTable::getData(int id){
    Data got;
    bool gotten = table[hash(id)]->getNode(id, &got);
    return (gotten ? got.data : "");
}

bool HashTable::removeEntry(int id){    
    bool removed = table[hash(id)]->deleteNode(id);
    count = removed ? --count : count;
    return removed;
}

int HashTable::getCount(){
    return count;
}

void HashTable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        cout << "Entry " << i + 1 << ": ";
        table[i]->printList();
    }
}

int HashTable::hash(int id){
    return id % HASHTABLESIZE;
}