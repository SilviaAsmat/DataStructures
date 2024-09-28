/*****************
*Name: Silvia Asmat
*Final
*Purpose:  Create a working undirected, unweighted graph class with all the standard methods for
 a data structure of that type.
********************/
#include "graph.h"

/****************PUBLIC METHODS*******************/

Graph::Graph() {
    numOfVertices = 0;
    graphNodes = {};
}
bool Graph::isEmpty() {
    return graphNodes.empty();
}
int Graph::getNumVertices() {
    return graphNodes.size();
}
int Graph::getNumEdges() {
    int count = 0;
    for (int i = 0; i < graphNodes.size(); i++) {
        count += graphNodes[i].adjNodes.size();
    }
    count = count/2;
    return count;
}
bool Graph::edgeExists(int idOne, int idTwo) {
    bool found = false;
    int i = 0;
    bool graphIsEmpty = graphNodes.empty();
    while(!graphIsEmpty && graphNodes[i].data.id != idOne) {
        i++;
    }
    if (!graphIsEmpty && graphNodes[i].data.id == idOne) {
        vector<Data> nodes = graphNodes[i].adjNodes;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].id == idTwo) {
                found = true;
            }
        }
    }
    return found;
}

bool Graph::getVertex(int id, struct Data* data) {
    bool found = false;
    data->id = -1;
    if(id >= 0) {
        for (int i = 0; i < graphNodes.size(); i++) {
            if (graphNodes[i].data.id == id) {
                data->id = graphNodes[i].data.id;
                found = true;
            }
        }
    }
    return found;
}

bool Graph::removeVertex(int removeVertexId) {
    bool removed = false;
    if (removeVertexId >= 0) {
        int removeIndex = indexOf(removeVertexId);
        if (removeIndex >= 0) {
            vector<Data> adjNodes = graphNodes[removeIndex].adjNodes;
            for (int i = 0; i < adjNodes.size(); i++){
                //Loop through adjNodes from the main list, remove vertex from adj lists
                int parentIndex = indexOf(adjNodes[i].id);
                GraphNode parentNode = graphNodes[parentIndex];
                int indexRemoveAdjId = indexOfAdjNode(removeVertexId, parentIndex);
                parentNode.adjNodes.erase(parentNode.adjNodes.begin()+indexRemoveAdjId);
            }
            //Remove vertex from main list
            graphNodes.erase(graphNodes.begin()+removeIndex);
            removed = true;
        }
    }
    return removed;
}

bool Graph::addEdge(int vertexOne, int vertexTwo) {
    bool added = false;
    int indexOne = indexOf(vertexOne);
    int indexTwo = indexOf(vertexTwo);
    if (indexOne >= 0 && indexTwo >= 0 && indexTwo != indexOne) {
        GraphNode vertexOne = graphNodes[indexOne];
        GraphNode vertexTwo = graphNodes[indexTwo];
        vertexTwo.adjNodes.emplace_back(vertexOne.data);
        vertexOne.adjNodes.emplace_back(vertexTwo.data);
        added = true;
    }
    return added;
}

bool Graph::addVertex(int parent, int newVertexId) {
    bool added = false;
    if (newVertexId >= 0) {
        if (graphNodes.empty()) {
            //Create new node data object
            Data newVertexData;
            newVertexData.id = newVertexId;
            //Create new GraphNode entry
            GraphNode newGraphNode;
            newGraphNode.data = newVertexData;
            //Add to main list
            graphNodes.push_back(newGraphNode);
            added = true;
        } else {
            int parentIndex = indexOf(parent);
            if(parentIndex >= 0) {
                GraphNode parentGraphNode = graphNodes[parentIndex];
                vector<Data> nodes = parentGraphNode.adjNodes;
                int adjNodeIndex = indexOfAdjNode(newVertexId, parentIndex);
                if (adjNodeIndex >= 0) {
                    //Vertex already exists, do nothing
                } else {
                    //Create new node data object
                    Data newVertexData;
                    newVertexData.id = newVertexId;
                    //Add new node to parent's adj list
                    parentGraphNode.adjNodes.push_back(newVertexData);
                    //Create new GraphNode entry
                    GraphNode newGraphNode;
                    newGraphNode.data = newVertexData;
                    newGraphNode.adjNodes.push_back(parentGraphNode.data);
                    //Add to main list
                    graphNodes.push_back(newGraphNode);
                    added = true;
                }
            }
        }
        
    }
    return added;
}
bool Graph::removeEdge(int vertexOne, int vertexTwo) {
    bool removed = false;
    int mainListIndexOne = indexOf(vertexOne);
    int mainListIndexTwo = indexOf(vertexTwo);
    if (mainListIndexOne >= 0 && mainListIndexTwo >= 0 && mainListIndexTwo != mainListIndexOne) {
        GraphNode mainVertexOne = graphNodes[mainListIndexOne];
        GraphNode mainVertexTwo = graphNodes[mainListIndexTwo];
        int adjIndexOne = indexOfAdjNode(vertexOne, mainListIndexOne);
        int adjIndexTwo = indexOfAdjNode(vertexTwo, mainListIndexTwo);
        mainVertexTwo.adjNodes.erase(mainVertexTwo.adjNodes.begin()+adjIndexOne);
        mainVertexOne.adjNodes.erase(mainVertexOne.adjNodes.begin()+adjIndexTwo);
        removed = true;
    }
    return removed;
}

void Graph::displayGraph(bool depthFirst, int id) {
    if (depthFirst) {
        depthFirstTraversal(id);
    } else {
        breadthFirstTraversal(id);
    }
}

/****************PRIVATE METHODS*******************/
void Graph::depthFirstTraversal(int id) {
    vector<bool> visited;
    visited.resize(graphNodes.size(),false);
    depthFirstTraversalRecursive(id, visited);
}

void Graph::depthFirstTraversalRecursive(int id, vector<bool> visited) {
    visited.resize(graphNodes.size(),false);
    int index = indexOf(id);
    if (index != -1) {
        visited[index] = true;
        cout << "Vertex:" << id << endl;
        vector<Data> adjNodes = graphNodes[index].adjNodes;
        for (int i = 0; i < adjNodes.size(); i++) {
            int mainListIndex = indexOf(adjNodes[i].id);
            if(!visited[mainListIndex]) {
                depthFirstTraversalRecursive(adjNodes[i].id, visited);
            }
        }
    }
}
void Graph::breadthFirstTraversal(int id) {
    vector<bool> visited;
    visited.resize(graphNodes.size(),false);
    breadthFirstTraversalRecursive(id, visited);
}
void Graph::breadthFirstTraversalRecursive(int id, vector<bool> visited) {
    visited.resize(graphNodes.size(),false);
    int index = indexOf(id);
    if(index != -1) {
        visited[index] = true;
        cout << "Vertex:" << id << endl;
        vector<Data> adjNodes = graphNodes[index].adjNodes;
        for (int i = 0; i < adjNodes.size(); i++) {
            int mainListIndex = indexOf(adjNodes[i].id);
            if(!visited[mainListIndex]) {
                breadthFirstTraversalRecursive(adjNodes[i].id, visited);
            }
        }
    }
}

//Will find index of given ID, otherwise will return -1
int Graph::indexOfAdjNode(int id, int indexOfParent) {
    int index = 0;
    bool found = false;
    vector<Data> adjNodes = graphNodes[indexOfParent].adjNodes;
    for (int i = 0; i < adjNodes.size(); i++) {
        if (adjNodes[i].id == id) {
            index = i;
            found = true;
        }
    }
    if (!found) {
        index = -1;
    }
    return index;
}

//Will find index of given ID, otherwise will return -1
int Graph::indexOf(int id) {
    int index = 0;
    bool graphIsEmpty = graphNodes.empty();
    while(!graphIsEmpty && index < graphNodes.size() && graphNodes[index].data.id != id) {
        index++;
    }
    bool elementFound = !graphIsEmpty && graphNodes[index].data.id == id;
    if (!elementFound) {
        index = -1;
    }
    return index;
}
