#include "GeneticAlg.hpp"
std::vector<std::vector<int>> GeneticAlg::getElites(std::vector<std::vector<int>> permutations) {
    std::vector<std::vector<int>> elites;
    std::vector<int> first = permutations[0], second = permutations[1];
    for (int i = 0; i < permutations.size(); i++) {
        double currentDist = matrix.getTotalDist(permutations[i]);
        if (currentDist < matrix.getTotalDist(first)) {
            second = first;
            first = permutations[i];
        } else if (currentDist < matrix.getTotalDist(second) && permutations[i] != first) {
            second = permutations[i];
        }
    }
    elites.push_back(first);
    elites.push_back(second); 
    return elites;
}
std::vector<std::vector<int>> GeneticAlg::getMutations(std::vector<std::vector<int>> permutations, int percent) {
    std::vector<std::vector<int>> mutations;
    std::vector<int> currentPermutation;
    if (percent > 100) {
        percent = 100;
    }
    for (int i = 0; i < (permutations.size() - 2) * ((double) percent / 100.00); i++) {
        currentPermutation = permutations[rand() % 4];
        for (int j = 0; j < rand() % 2 + 1; j++) {
            std::swap(currentPermutation[rand() % currentPermutation.size()], currentPermutation[rand() % currentPermutation.size()]);
        }
        mutations.push_back(currentPermutation);
    }
    return mutations;
}

GeneticAlg::GeneticAlg(DistMatrix matrix) {
    srand(time(NULL));
    this->matrix = matrix;
}
double GeneticAlg::run(InputHandler input) {
    clock_t timer = clock();
    int numCities = input.getNumCities();
    int numToursInGeneration = input.getNumToursInGeneration();
    int numGenerations = input.getNumGenerations();
    int mutationPercentage = input.getMutationPercentage();   
    std::vector<std::vector<int>> generation, elites, mutations, permutations;
    std::vector<int> startingPermutation = matrix.getFirstPermutation(numCities); 
    generation = matrix.getNextPermutations(startingPermutation, numToursInGeneration);
    for (int i = 0; i < numGenerations; i++) {
        elites = getElites(generation);
        mutations = getMutations(generation, mutationPercentage);
        startingPermutation = generation[generation.size() - 1];
        int permutationsToAdd = generation.size() - (elites.size() + mutations.size());
        permutations = matrix.getNextPermutations(startingPermutation, permutationsToAdd);
        generation.clear();
        for (std::vector<int> p : elites) {
            generation.push_back(p);
        }
        for (std::vector<int> p : mutations) {
            generation.push_back(p);
        }
        for (std::vector<int> p : permutations) {
            generation.push_back(p);
        }
    }
    double lowestDist = matrix.getTotalDist(generation[0]);
    std::cout << "Cost from the ga: " << lowestDist << std::endl;
    std::cout << "Time the ga took to run: " << float(clock() - timer) /  CLOCKS_PER_SEC << " s" << std::endl;
    return lowestDist;
}