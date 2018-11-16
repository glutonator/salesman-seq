//
// Created by filip on 15.11.18.
//

#include <numeric>
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include "Algorithm.h"
#include "RandomVector.h"

Algorithm::Algorithm(int T, int L, int numberOfNodes) {

    Graph *graph = new Graph(numberOfNodes);
    graph->createComleteGraph();
    graph->printGraph();

    //to jest ważne!!!!
    this->graph=graph;


//    this->k = k;
    this->T = T;
    this->L = L;

    //popluation of vector
    simpleOrderedPermutation = vector<int>(numberOfNodes);
    iota(std::begin(simpleOrderedPermutation), std::end(simpleOrderedPermutation), 0);
    //sorting, not necessary
    sort(begin(simpleOrderedPermutation), end(simpleOrderedPermutation));

    previousPermutation = simpleOrderedPermutation;
    previousPermutationValue = graph->countWeightOfPath(simpleOrderedPermutation);

    bestPermutation = simpleOrderedPermutation;
    bestPermutationValue = previousPermutationValue;
}

vector<int> Algorithm::nextPermutation() {
    RandomVector *randomVector = new RandomVector();
    vector<int> out = randomVector->generateRandVector(simpleOrderedPermutation);
//    cout << "simpleOrderedPermutation" << endl;
//    for (auto it = simpleOrderedPermutation.begin(); it != simpleOrderedPermutation.end(); ++it) {
//        cout << *it;
//    }
//    cout << endl;
//    cout << "out" << endl;
//
//    for (auto it = out.begin(); it != out.end(); ++it) {
//        cout << *it;
//    }
//    cout << endl;


    return out;
}

//int Algorithm::differenceInDistance(vector<int> newPermutation) {
//    int newDistance = graph->countWeightOfPath(newPermutation);
//    int out = newDistance - this->previousPermutationValue;
//    return out;
//}

void Algorithm::changeValuesOfPermutations(vector<int> newPermutation) {
    // newPermutation is x* in algorithm

    int newPermutationValue = graph->countWeightOfPath(newPermutation);
    int diff = newPermutationValue - this->previousPermutationValue;

    if (diff <= 0) {
        //x0 = x*
        this->previousPermutation = newPermutation;
        this->previousPermutationValue = newPermutationValue;
        //x_opt = x*
        this->bestPermutation = newPermutation;
        this->bestPermutationValue = newPermutationValue;
    } else {
        double r = randomValueZeroToOne(0, 1);
        double exponent = exp(-(this->previousPermutationValue - this->bestPermutationValue / this->T));
        if (r < exponent) {
            //x0 = x*
            this->previousPermutation = newPermutation;
            this->previousPermutationValue = newPermutationValue;
        }
    }


}

double Algorithm::randomValueZeroToOne(const int &min, const int &max) {
    //todo: to te zjest szansa że nie jest w pełni thread safe ze wzglę du na wykorzystanie seed z czasu
    //todo: może zrobić tego seeda statycznym???
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static thread_local std::mt19937 generator(seed);
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

void Algorithm::annealingMethod() {
    int epsilon = 20;
    //wykonuje się aż temp nie spadnie poniżej epsilon
    while (this->T > epsilon) {
        //k - liczba kroków podczasu szukania minimu wokół jednego rozwiązania
        for (int k = 0; k < L; ++k) {
            changeValuesOfPermutations(this->nextPermutation());

        }
        changeTemp();
    }
}

double Algorithm::changeTemp() {
    double alfa = 0.89;
    double temp = this->T;
    temp = (1 - alfa) * temp;
    return temp;
}






