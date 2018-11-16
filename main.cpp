#include <iostream>
#include <random>
#include <chrono>
#include "Graph.h"
#include "Algorithm.h"

using namespace std;

int main() {
    int numberOfNodes = 10;
    double temperature =200.0;
    int loopSteps =20;

    Algorithm algorithm = Algorithm(temperature,loopSteps,numberOfNodes);

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    algorithm.annealingMethod();

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";


    return 0;
}