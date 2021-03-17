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
double BruteAlg::run(InputHandler input) {
    clock_t timer = clock();
    int numCities = input.getNumCities();
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
    std::cout << "Number of cities ran: " << numCities << std::endl;
    std::cout << "Optimal cost from brute force: " << lowestDist << std::endl;
    std::cout << "Time the brute force algorithm took: " << float(clock() - timer) /  CLOCKS_PER_SEC << " s" << std::endl;
    return lowestDist;
}