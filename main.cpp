#include "DataMatrix.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
int main() {
    //asks users for input
    int numCities = 10, numToursInGeneration = 100, numGenerations = 100, mutationPercentage = 70;
    std::cout << "Number of cities: ";
    std::cin >> numCities;
    std::cout << "Tours per generation: ";
    std::cin >> numToursInGeneration;
    std::cout << "Number of generations: ";
    std::cin >> numGenerations;
    std::cout << "Percentage of mutations per generation: ";
    std::cin >> mutationPercentage;

    //loads distances.txt
    DataMatrix dm("distances.txt");

    //sets timer to current time
    clock_t timer = clock();
    
    //genetic algorithm loop
    std::vector<std::vector<int>> generation, elites, mutations, permutations;
    generation = dm.getPermutations(dm.getFirstPermutation(numCities), numToursInGeneration);   //gets the initial list of tours
    for (int i = 0; i < numGenerations; i++) {
        elites = dm.getElites(generation);      //gets two elites from generations
        mutations = dm.getMutations(generation, mutationPercentage);    //gets a list of tours that are mutated
        permutations = dm.getPermutations(generation[generation.size() - 1], generation.size() - (elites.size() + mutations.size()));   //gets the remaining tours needed if space is left in the generation
        generation.clear();     //empty the current generation
        for (std::vector<int> p : elites) {         //fill the generation with the first two elites
            generation.push_back(p);
        }
        for (std::vector<int> p : mutations) {      //next place in the mutations
            generation.push_back(p);
        }
        for (std::vector<int> p : permutations) {    //if there are any permutations to be added, add them in
            generation.push_back(p);
        }
    }
    //output results and get current time difference
    std::cout << "Genetic algorithm produced: " << dm.getCost(generation[0]) << " in " << float(clock() - timer) /  CLOCKS_PER_SEC << "s " << std::endl;

    //start the clock again
    timer = clock();

    //brute force algorithm loop
    permutations = dm.getPermutations(dm.getFirstPermutation(numCities), dm.factorial(numCities));  //get the full list of permutations
    std::vector<int> lowest = permutations[0];
    for (int i = 0; i < permutations.size(); i++) {
        if (dm.getCost(permutations[i]) < dm.getCost(lowest)) { //if the current iteration has a lower cost, it is the new lowest
            lowest = permutations[i];
        }
    }
    //output results and get current time difference
    std::cout << "Brute force algorithm produced: " << dm.getCost(lowest) << " in " << float(clock() - timer) /  CLOCKS_PER_SEC << "s " << std::endl;

    //output comparison
    std::cout << "Genetic algorithm produced a solution " << dm.getCost(generation[0]) / dm.getCost(lowest) * 100 << "% of the optimal solution" << std::endl;
    return 0;
};