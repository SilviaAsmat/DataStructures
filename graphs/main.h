/*****************
*Name: Silvia Asmat
*Final
*Purpose:  Create a working undirected, unweighted graph class with all the standard methods for
 a data structure of that type.
**********************/

int main(int argc, char** argv) {

    srand(time(NULL));
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
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    Graph graph = Graph();
    // show it is empty by calling getNumVertices and displayGraph
    int numOfEdges;
    int numOfVertices;
    numOfVertices = graph.getNumVertices();
    numOfEdges = graph.getNumEdges();

    int GRAPHSIZE = numOfVertices;
    cout << "number of vertices: " << numOfVertices << endl;
    graph.displayGraph(false, 1);
    cout << "------------------------------------" << endl;
    cout << "ADDING ALL TEST DATA" << endl;
    cout << "------------------------------------" << endl;
    bool inserted = false;
    for (int i = 0; i < testdatasize; i++) {
        inserted = graph.addVertex(ids[i], ids[-1+i]);
        numOfVertices = graph.getNumVertices();
        numOfEdges = graph.getNumEdges();
        cout << "inserted: " << ids[i] << "\tnumOfVertices: " << numOfVertices << "\tnumOfEdges: " << numOfEdges << endl;
    }
    
    graph.displayGraph(false, 1);

    //remove all elements in graph
    cout << "------------------------------------" << endl;
    cout << "EMPTYING graph COMPLETELY" << endl;
    cout << "------------------------------------" << endl;
    bool removedVertices = false;
    bool removedEdges = false;
    for (int i = 0; i < testdatasize; i++) {
        
        removedVertices = graph.removeVertex(ids[i]);
        removedEdges = graph.removeEdge(ids[i],ids[-1+1]);
        cout << "\nremoving: " << ids[i] << " : " << strs[i] << "..." ;
        if (removedVertices || removedEdges) {
            cout << " removed";
        } else {
            cout << " not found";
        }
        int num = graph.getNumVertices();
        cout << "\tcount: " << num << endl;
    }
    graph.displayGraph(false,1);
    
    //fill halfway
    cout << "------------------------------------" << endl;
    cout << "FILLING graph HALFWAY" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < GRAPHSIZE/HALF; i++) {
        inserted = graph.addVertex(ids[i], ids[i+1]);
        numOfVertices = graph.getNumVertices();
        numOfEdges = graph.getNumEdges();
        cout << "inserted: " << ids[i] << "\tnumOfVertices: " << numOfVertices << "\tnumOfEdges: " << numOfEdges << endl;
    }
    graph.displayGraph(false,1);

    //find data
    cout << "------------------------------------" << endl;
    cout << "FINDING graph DATA" << endl;
    cout << "------------------------------------" << endl;
    struct Data* findData = new Data;
    bool found = false;
    for (int i = 0; i < numOfVertices; i++) {
        findData->id = i;
        found = graph.getVertex(ids[i], findData);
        cout << "search id:" << ids[i] << "found id: " << findData->id << endl;
    }
    //overfill
    cout << "------------------------------------" << endl;
    cout << "OVERFILLING graph " << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < GRAPHSIZE*MULTIPLIER; i++) {
        inserted = graph.addVertex(ids[i], ids[-1+i]);
        numOfVertices = graph.getNumVertices();
        numOfEdges = graph.getNumEdges();
        cout << "inserted: " << ids[i] << "\tnumOfVertices: " << numOfVertices << "\tnumOfEdges: " << numOfEdges << endl;
    }
    graph.displayGraph(false,1);
    //try empty more than amount of existing elements
    cout << "------------------------------------" << endl;
    cout << "OVER EMPTYING graph" << endl;
    cout << "------------------------------------" << endl;
    removedVertices = false;
    removedEdges = false;
    for (int i = 0; i < testdatasize*BUFFERSIZE; i++) {
        removedVertices = graph.removeVertex(ids[i]);
        removedEdges = graph.removeEdge(ids[i],ids[-1+1]);
        cout << "inserted: " << ids[i] << "\tnumOfVertices: " << numOfVertices << "\tnumOfEdges: " << numOfEdges << endl;
        if (removedVertices || removedEdges) {
            cout << " removed";
        } else {
            cout << " not found";
        }
        cout << endl;
    }
    graph.displayGraph(false,1);

    return 0;
}
