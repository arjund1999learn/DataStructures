/* 
 Name: Arjun Devireddy
 Coding 07
 Purpose: This program tests the hashtable object
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here

    HashTable hashtable;
    int get;
    int remove;
    
    // show it is empty by calling getCount and printTable

    cout << "Getting count: " << hashtable.getCount() << endl << endl;
    cout << "Getting table: " << endl; 
    hashtable.printTable();
    cout << "======================" << endl;

    // try and put ALL the test data into the table and show what happens
    cout << "Inseting test data" << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "Inserting " << ids[i] << ": " << strs[i] << "... ";
        if(hashtable.insertEntry(ids[i], &strs[i])){
            cout << "success" << endl;
        }
        else{
            cout << "failed" << endl;
        }
    }

    cout << "Getting count: " << hashtable.getCount() << endl << endl;
    cout << "Getting table: " << endl; 
    hashtable.printTable();
    cout << "======================" << endl;
    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

   // getting random values
   cout << "Getting random values " << endl;
   for(int i = 0; i < BASE; i++) {
        get = rand() % (testdatasize - 1);
        cout << "Getting... "; 
        if(hashtable.getData(ids[get]) != ""){
            cout << "found " << ids[get] << ": " << hashtable.getData(ids[get]) << endl;
        }
        else{
            cout << "failed to find " << ids[get] << endl;
        }
   }
   // deleting random values
   for(int i = 0; i < BASE; i++) {
        remove = rand() % (testdatasize - 1);
        cout << "Deleting "  << ids[remove] << "... "; 
        if(hashtable.removeEntry(ids[remove])){
            cout << "Success " << endl;
        }
        else{
            cout << "Failed " << endl;
        }
   }

    //getting count and printing list after delete

    cout << "Getting count: " << hashtable.getCount() << endl << endl;
    cout << "Getting table: " << endl; 
    hashtable.printTable();
    cout << "======================" << endl;

    //getting elements after delete
    cout << "Getting random values " << endl;
   for(int i = 0; i < BASE; i++) {
        get = rand() % (testdatasize - 1);
        cout << "Getting... "; 
        if(hashtable.getData(ids[get]) != ""){
            cout << "found " << ids[get] << ": " << hashtable.getData(ids[get]) << endl;
        }
        else{
            cout << "failed to find " << ids[get] << endl;
        }
   }
    
    
    return 0;
}
