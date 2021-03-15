#include "DataMatrix.hpp"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
int main() {
    srand(time(NULL));
    int numCities = 5, numToursInGeneration = 10, numGenerations = 5, mutationPercentage = 25;
    /*
    std::cout << "Number of cities: ";
    std::cin >> numCities;
    std::cout << "Tours per generation: ";
    std::cin >> numToursInGeneration;
    std::cout << "Number of generations: ";
    std::cin >> numGenerations;
    std::cout << "Percentage of mutations per generation: ";
    std::cin >> mutationPercentage;
    */
    DataMatrix dm("distances.txt");
    
    std::vector<std::vector<int>> generation, elites, mutations, permutations;
    generation = dm.getPermutations(dm.getFirstPermutation(numCities), numToursInGeneration);
    for (int i = 0; i < numGenerations; i++) {
        elites = dm.getElites(generation);
        mutations = dm.getMutations(generation, mutationPercentage);
        permutations = dm.getPermutations(generation[generation.size() - 1], generation.size() - (elites.size() + mutations.size()));
        generation.clear();
        for (std::vector<int> p : elites) {
            generation.push_back(p);
            for (int j : p) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (std::vector<int> p : mutations) {
            generation.push_back(p);
            for (int j : p) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (std::vector<int> p : permutations) {
            generation.push_back(p);
            for (int j : p) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int j = 0; j < generation.size(); j++) {
            for (int k = 0; k < generation[j].size(); k++) {
                std::cout << generation[j][k] << " ";
            }
            std::cout << dm.getCost(generation[j]) << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
};