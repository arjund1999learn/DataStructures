/*
 Name: Arjun Devireddy
 Coding 06
 Purpose: This program creates a dynamic two way linked list as well as
          methods to add and delete objects from the list.
 */
#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int add, string* adding){
    bool added = false;
    bool skip = false;
    if(add > 0 && adding != NULL){
        Node *current = head;
        added = false;
        if(head == NULL){ //node is empty
            addHead(add, adding, &added);
        }
        else{
            while(current && !skip && !added){
                if(current->data.id == add){
                    added = false;
                    skip = true;
                }
                else if(head->data.id > add && added == false && skip == false){ //new node at head
                    addHead(add, adding, &added);
                }
                else if(current->data.id < add && current->next == NULL && added == false && skip == false){ //new node at tail
                    addTail(add, adding, &added, current);
                    current = current->next;
                }
                else if(current->data.id > add && added == false && skip == false){  //general case
                    addGeneral(add, adding, &added, current);
                }
                current = current->next;       
            }                      
        }       
    }
    return added;
}

bool LinkedList::deleteNode(int del){
    bool deleted = false;
    Node* current = head;
    while(current && !deleted){
        if(current->data.id == del){
            if(current == head){
                deleteHead();
            }
            else if(current->next == NULL){
                current->prev->next = NULL;
                delete current;
            }
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            deleted = true;
        }
        current = current -> next;
    }
    return deleted;
}

bool LinkedList::getNode(int get, Data* recieve){
    bool got = false;
    if(head != NULL){
        Node *current = head;
        while(current){
            if(current->data.id == get){
                recieve->id = current->data.id;
                recieve->data = current->data.data; 
                got = true;
            }
            current = current->next;
        }
    }
    return got;
}

void LinkedList::printList(bool backward){
    if(head != NULL){
        Node *current = head;
        int nodeCount = 1;
        if(backward){
            while(current->next){
                current = current->next;
            }
            while(current){
                cout << "\t" << nodeCount << ": " << current->data.id << ": " << current->data.data << endl;
                current = current->prev;
                nodeCount++;
            }
        }
        else{
            while(current){
                cout << "\t" << nodeCount << ": " << current->data.id << ": " << current->data.data << endl;
                current = current->next;
                nodeCount++;
            }
        }
        
    }
}
int LinkedList::getCount(){
    int count = 0;
    if(head != NULL){
        Node *current = head;
        while(current){
            count++;
            current = current->next;
        }
    }
    return count;
}

bool LinkedList::clearList(){
    while(head){
        deleteHead();
    }  
    return true;
}

bool LinkedList::exists(int e){
    bool found = false;
    if(head != NULL){
        Node *current = head;
        while(current){
            if(current->data.id == e){
                found = true;
            }
            current = current->next;
        }
    }
    return found;
}

void LinkedList::deleteHead(){
    Node *current = head;
    if(current->next != NULL){
        head = current->next;
        head->prev = NULL;
        delete current;
    }
    else{
        delete current;
        head = NULL;
    }
}

void LinkedList::addHead(int add, string* adding, bool* added){
    Node *newNode = createNode(add, adding);
    if(head != NULL){
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
    }
    head = newNode;
    *added = true;

}

void LinkedList::addTail(int add, string* adding, bool* added, Node* current){
    Node *newNode = createNode(add, adding);
    newNode->next = NULL;
    newNode->prev = current;
    current->next = newNode;
    *added = true;
}

void LinkedList::addGeneral(int add, string* adding, bool* added, Node* current){
    Node *newNode = createNode(add, adding);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    *added = true;
}

Node* LinkedList::createNode(int add, string* adding){
    Node *newNode = new Node;
    newNode->data.id = add;
    newNode->data.data = *adding;
    return newNode;
}

