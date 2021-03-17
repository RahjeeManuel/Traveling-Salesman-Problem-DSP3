#include "BruteAlg.hpp"
int BruteAlg::factorial(int num) {
    if (num > 1) {
        return num * factorial(num - 1);
    } else {
        return 1;
    }   
}

BruteAlg::BruteAlg(DistMatrix matrix) {
    this->matrix = matrix;
}
double BruteAlg::run(int numCities) {
    std::vector<int> startingPermutation = matrix.getFirstPermutation(numCities); 
    int loopAmount = factorial(numCities);  
    std::vector<std::vector<int>> permutations = matrix.getNextPermutations(startingPermutation, loopAmount);
    double lowestDist = matrix.getTotalDist(permutations[0]);
    for (int i = 0; i < permutations.size(); i++) {
        double currentDist = matrix.getTotalDist(permutations[i]);
        if (currentDist < lowestDist) {
            lowestDist = currentDist;
        }
    }
    return lowestDist;
}