//
// Created by filip on 15.11.18.
//

#ifndef SALESMAN_SEQ_GRAPH_H
#define SALESMAN_SEQ_GRAPH_H

#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int numberOfNodes;
    vector<vector<pair<int, int> > > adjacencyList;

public:

    Graph(int numberOfNodes);

    void addEdge(int node1, int node2, int weight);

    void printGraph();

    list <vector<int>> findShortestPath();

    void findShortestPathBetter();


    void createComleteGraph();

    int countWeightOfPath(vector<int> singlePermutation);

    int getWeight(int node1, int node2);

    vector <int> randomNodeVector();
};


#endif //SALESMAN_SEQ_GRAPH_H
