/*
 Name: Arjun Devireddy
 Coding 07
 Purpose: This program creates an graph and functions 
 to add and find vertices and edges of the graph
 */
 #include "graph.h"

Graph::Graph(){
    eCount = 0;
    vCount = 0;
}

bool Graph::createVertex(int id){
    bool createdV = false;
    Node temp = {id, false};
    if(graph.empty() && id > 0){
        graph.push_back({});
        graph[0].push_back(temp);
        createdV = true;
    }
    else if(!isVertex(id) && id > 0){
        graph[0].push_back(temp);
        graph.push_back({});
        for (int i = 0; i <= graph.size(); i++){
            while(graph[i].size() < graph[0].size()){
                graph[i].push_back({graph[0][graph[i].size()].id, false});
            }
        }
        vCount++;
        createdV = true;
    }
    return createdV;
}

bool Graph::createEdge(int id1, int id2){
    bool createdE = false;
    int point1 = -1;
    int point2 = -1;
    if(!graph.empty()){
        for(int i = 0; i < graph[0].size(); i++){
            if(id1 == graph[0][i].id){
                point1 = i;
            }
            else if(id2 == graph[0][i].id){
                point2 = i;
            }
        }
        if(point1 != -1 && point2 != -1){
            graph[point1][point2].edge = true;
            graph[point2][point1].edge = true;
            eCount++;
            createdE = true;
        }
    }
    return createdE;
}


bool Graph::deleteEdge(int id1, int id2){
    bool deleted = false;
    int point1 = -1;
    int point2 = -1;
    if(!graph.empty()){
        for(int i = 0; i < graph[0].size(); i++){
            if(id1 == graph[0][i].id){
                point1 = i;
            }
            else if(id2 == graph[0][i].id){
                point2 = i;
            }
        }
        if(point1 != -1 && point2 != -1 && graph[point1][point2].edge == true){
            graph[point1][point2].edge = false;
            graph[point2][point1].edge = false;
            eCount--;
            deleted = true;
        }
    }
    return deleted;
}

bool Graph::isVertex(int id){
    bool vertexFound = false;
    if(!graph.empty()){
        for (int i = 0; i < graph.size(); i++){
            if(graph[i][i].id == id){
                vertexFound = true;
            }
        }
    }
    return vertexFound;
}

int Graph::edgeCount(){
    return eCount;
}

int Graph::vertexCount(){
    return vCount;
}

void Graph::displayGraph(){
    cout << "Displaying Graph" << endl;
    cout << "====================================" << endl;
    cout << "Vertices: " << vertexCount() << endl;
    cout << "Edges: " << edgeCount() << endl;
    if(!graph.empty()){
        for(int i = 0; i < graph.size(); i++){
            cout << graph[0][i].id << ": ";
            for(int j = 0; j < graph[i].size(); j++){
                cout << graph[i][j].id << "," << graph[i][j].edge << " -> ";
            }
            cout << endl;
        }
    }
}

