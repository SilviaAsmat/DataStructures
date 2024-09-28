/*****************
*Name: Silvia Asmat
*Final
*Purpose:  Create a working undirected, unweighted graph class with all the standard methods for
 a data structure of that type.
**********************/

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include "data.h"

using namespace std;

class Graph {
public:
    Graph();
    bool isEmpty();
    int getNumVertices();
    int getNumEdges();
    bool edgeExists(int, int);
    bool getVertex(int, struct Data*);
    bool addVertex(int, int);
    bool removeVertex(int);
    bool addEdge(int, int);
    bool removeEdge(int, int);
    void displayGraph(bool, int);
private:
    int numOfVertices;
    vector<GraphNode> graphNodes;
    void depthFirstTraversal(int);
    void depthFirstTraversalRecursive(int, vector<bool>);
    void breadthFirstTraversal(int);
    void breadthFirstTraversalRecursive(int, vector<bool>);
    int indexOf(int);
    int indexOfAdjNode(int, int);
};
#endif /* GRAPH_GRAPH_H */

