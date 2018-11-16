#include <iostream>
#include <random>
#include "Graph.h"
#include "Algorithm.h"


int main() {
//    int numberOfNodes = 5;
//
//    Graph *graph = new Graph(numberOfNodes);
//
//    graph->createComleteGraph();
//    graph->printGraph();
//
//
//    graph->findShortestPathBetter();

    Algorithm algorithm = Algorithm(100,10,5);
//    vector<int> qqq = algorithm->nextPermutation();
    algorithm.annealingMethod();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}