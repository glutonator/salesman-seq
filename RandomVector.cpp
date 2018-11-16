//
// Created by filip on 15.11.18.
//

#include <chrono>
#include <algorithm>
#include <random>
#include <iostream>
#include "RandomVector.h"

vector<int> RandomVector::generateRandVector(vector<int> singlePermutation) {
    //todo: nie wiem czy tutuj będzie totalny rand dla równoległych wątków - konieczna poprawka albo weryfikacja
    //todo: raczej trzeba bedzie to przerobić na coś thread safe
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine(seed);
    std::shuffle(std::begin(singlePermutation), std::end(singlePermutation), rng);
    for (auto it = singlePermutation.begin(); it != singlePermutation.end(); ++it) {
//        cout<<*it;
    }
//    cout<<endl;
    return singlePermutation;
}

RandomVector::RandomVector() {

}

