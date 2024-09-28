/*****************
*Name: Silvia Asmat
*Final
*Purpose:  Create a working undirected, unweighted graph class with all the standard methods for
 a data structure of that type.
**********************/

#ifndef GRAPHS_DATA_H
#define GRAPHS_DATA_H

#include <string>
#include <vector>
using std::string;

struct Data {
    int id;
};
struct GraphNode {
    Data data;
    std::vector<Data> adjNodes = {};
};

#endif /* DATA_H */
