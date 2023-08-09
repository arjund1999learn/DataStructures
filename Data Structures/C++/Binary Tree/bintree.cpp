/*
 Name: Arjun Devireddy
 Coding 07
 Purpose: This program creates an binary tree and functions 
 to add, delete, find, and print nodes of the tree
 */

#include "bintree.h"
BinTree::BinTree(){
    count = 0;
    root = NULL;
}
bool BinTree::isEmpty(){
    return count == 0;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* temp){
    bool gotRoot = false;
    if(count != 0){
        temp->id = root->data.id;
        temp->information = root->data.information;
        gotRoot = true;
    }
    else{
        temp->id = -1;
        temp->information = "";
    }
    return gotRoot; 
}

bool BinTree::addNode(int id, const string* info){
    bool added = false;
    if(info != NULL && id > 0){
        DataNode* newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = NULL;
        newNode->right = NULL;
        added = addNode(newNode, &root);
        if(added){
            count++;
        }
    } 
    return added;
}

bool BinTree::addNode(DataNode* newNode, DataNode** root){
    bool adds = false;
    if (!(*root)){
        (*root) = newNode;
        adds = true;
    }
    else if((*root)->data.id > newNode->data.id){
        adds = addNode(newNode, &((*root)->left));
    }
    else{
        adds = addNode(newNode, &((*root)->right));
    }
    return adds;
}

bool BinTree::contains(int id){
    bool contained = false;
    if(id > 0){
        contained = contains(id, root);
    }
    return contained;
}

bool BinTree::contains(int id, DataNode* root){
    bool conts = false;
    if(root){
        if(root->data.id == id){
            conts = true;
        }
        else if(root->data.id > id){
            conts = contains(id, root->left);
        }
        else{
            conts = contains(id, root->right);
        }
    }
    return conts;
}

bool BinTree::getNode(Data* temp, int id){
    bool gotten = false;
    if(id > 0){
        gotten = getNode(temp, id, root);
    }
    return gotten;
}

bool BinTree::getNode(Data* temp, int id, DataNode* root){
    bool gets = false;
    if(root){
        if(root->data.id == id){
            temp->id = root->data.id;
            temp->information = root->data.information;
            gets = true;
        }
        else if(root->data.id > id){
           gets = getNode(temp, id, root->left);
        }
        else{
           gets = getNode(temp, id, root->right);
        }
    }
    return gets;
}

int BinTree::getHeight(){
    return getHeight(root);
}

int BinTree::getHeight(DataNode* root){
    int lh = 0;
    int rh = 0;
    int h = 0;
    if(root){
        lh = getHeight(root->left);
        rh = getHeight(root->right);
        h = 1 + std::max(lh, rh);
    }
    return h;
}

void BinTree::clear(){
    clear(root);
    root = NULL;
    count = 0;
}

void BinTree::clear(DataNode* root){
    if(root){
        clear(root->left);
        clear(root->right);
        root->left = NULL;
        root->right = NULL;
        delete root;
    }
    return;
}

bool BinTree::removeNode(int id){
    int tempcount = count;
    root = removeNode(id, root);
    return (count < tempcount);
}

DataNode* BinTree::removeNode(int id, DataNode* root){
    if(root != NULL){
        if(root->data.id > id){
            root->left = removeNode(id, root->left);
        }
        else if(root->data.id < id){
            root->right = removeNode(id, root->right);
        }
        else{
            DataNode* temp;
            if(root->left == NULL){
                temp = root->right;
                delete root;
                root = temp;
                count--;
            }
            else if(root->right == NULL){
                temp = root->left;
                delete root;
                root = temp;
                count--;
            }
            else{   
                temp = minValueNode(root->right);
                root->data.id = temp->data.id;
                root->data.information = temp->data.information;
                root->right = removeNode(temp->data.id, root->right);
            }
        }
    }
    return root;
}

void BinTree::displayTree(){
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;
    if(isEmpty()){
        cout << "Tree is empty" << endl;
    }
    else{
        cout << "Tree is not empty" << endl;
    }
    cout << "Height " << getHeight() << endl;
    cout << "Node Count: " << getCount() << endl;
    cout << endl;
    cout << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl;
    cout << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl;
    cout << "Post-Order Traversal" << endl;
    displayPostOrder();
    cout << "==============================================" << endl;
}

void BinTree::displayPreOrder(){
    displayPreOrder(root);
}

void BinTree::displayInOrder(){
    displayInOrder(root);
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

void BinTree::displayPreOrder(DataNode* root){
    if (root){
        cout << root->data.id << " " << root->data.information << endl;
        if (root->left) {
            displayPreOrder(root->left);
        }
        if (root->right) {
            displayPreOrder(root->right);
        }
    }
    return;
}

void BinTree::displayPostOrder(DataNode* root){
    
    if (root) {
        if (root->left) {
            displayPostOrder(root->left);
        }
        if (root->right) {
            displayPostOrder(root->right);
        }
        cout << root->data.id << " " << root->data.information << endl;
    }
    return;
}

void BinTree::displayInOrder(DataNode* root){
    if (root) {
        if (root->left) {
            displayInOrder(root->left);
        }
        cout << root->data.id << " " << root->data.information << endl;
        if (root->right) {
            displayInOrder(root->right);
        }
    }

    return;
}

BinTree::~BinTree(){
    clear();
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
    current = current->left;
    }
    return current;
}

