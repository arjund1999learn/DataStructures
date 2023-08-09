/*
 Name: Arjun Devireddy
 Coding 10
 Purpose: This file is a header for graph.cpp
 */
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
struct Node{
    int id;
    bool edge;
};

class Graph{
    public:
        Graph();
        bool createVertex(int);
        bool createEdge(int, int);
        bool deleteEdge(int,int);
        bool isVertex(int);
        int edgeCount();
        int vertexCount();
        void displayGraph();
    private:
        vector<vector<Node>> graph;
        int eCount;
        int vCount;
};
#endif //GRAPH_H