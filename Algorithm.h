//
// Created by filip on 15.11.18.
//

#ifndef SALESMAN_SEQ_ALGORITHM_H
#define SALESMAN_SEQ_ALGORITHM_H

#include <vector>
#include "Graph.h"

using namespace std;

class Algorithm {
private:

    //temperature = T
    double temerature;
    //loopSteps = L
    int loopSteps;

    //zawiera uporzadkowne rosnąco numery nodów
    std::vector<int> simpleOrderedPermutation;

    //poprzednia permutacja - x^0
    std::vector<int> previousPermutation;
    int previousPermutationValue;

    //permutajca z najkrótszą drogą - x_opt
    std::vector<int> bestPermutation;
    int bestPermutationValue;

    Graph *graph;

public:
    Algorithm(double temperature, int loopSteps, int numberOfNodes);

    vector<int> nextPermutation();

//    int differenceInDistance(vector<int> newPermutation );

    void changeValuesOfPermutations(vector<int> newPermutation);

    double randomValueZeroToOne(const int &min, const int &max);

    void annealingMethod();

    void changeTemp();

    void printEnd();

};


#endif //SALESMAN_SEQ_ALGORITHM_H
