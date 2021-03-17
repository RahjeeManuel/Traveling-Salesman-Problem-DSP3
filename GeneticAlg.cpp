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
    this->matrix = matrix;
}
double GeneticAlg::run(int numCities, int numToursInGeneration, int numGenerations, int mutationPercentage) {
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
    return matrix.getTotalDist(generation[0]);
}