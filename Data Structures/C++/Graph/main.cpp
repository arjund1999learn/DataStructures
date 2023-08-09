/*
 Name: Arjun Devireddy
 Coding 10
 Purpose: This program is to thoughrly test the graph function
 */
#include "main.h"

int main(){
    srand(time(0));

    int arr[] = {-1, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
    Graph graph;

    //Testing EMPTY graph
    graph.displayGraph();
    cout << "Testing Empty graph" << endl << endl;
    cout << "Testing createEdge" << endl;
    if(graph.createEdge(10, 15)){
        cout << "Success" << endl;
    }
    else{
        cout << "Failed" << endl;
    }

    cout << "Testing deleteEdge" << endl;
    if(graph.deleteEdge(10, 15)){
        cout << "Success" << endl;
    }
    else{
        cout << "Failed" << endl;
    }

    cout << "Testing isVertex" << endl;
    if(graph.isVertex(10)){
        cout << "Success" << endl;
    }
    else{
        cout << "Failed" << endl;
    }
    
    cout << "Filling Graph" << endl;
    for(int i = 0; i < TESTSIZE; i++){
        int id = rand() % 12;
        if(graph.createVertex(arr[id])){
            cout << "Added " << arr[id] << endl;
        }
        else{
            cout << "Failed to add: " << arr[id] << endl;
        }
    }
    graph.displayGraph();

    for(int i = 0; i < TESTSIZE; i++){
        int id = rand() % 12;
        int id1 = rand() % 12;
        if(graph.createEdge(arr[id], arr[id1])){
            cout << "Added " << arr[id] << ", " << arr[id1] << endl;
        }
        else{
            cout << "Failed to add: " << arr[id] << ", " << arr[id1] << endl;
        }
    }
    graph.displayGraph();

    for(int i = 0; i < TESTSIZE; i++){
        int id2 = rand() % 12;
        int id3 = rand() % 12;
        if(graph.deleteEdge(arr[id2], arr[id3])){
            cout << "Removed " << arr[id2] << ", " << arr[id3] << endl;
        }
        else{
            cout << "Failed to remove: " << arr[id2] << ", " << arr[id3] << endl;
        }
    }
    graph.displayGraph();

    for(int i = 0; i < TESTSIZE; i++){
        int id = rand() % 12;
        if(graph.isVertex(arr[id])){
            cout << "Found: " << arr[id] << endl;
        }
        else{
            cout << "Failed to find: " << arr[id] << endl;
        }
    }
   
}