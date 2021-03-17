#include "DistMatrix.hpp"
#include "BruteAlg.hpp"
#include "GeneticAlg.hpp"
#include <iostream>
#include <time.h>
int main() {
    srand(time(NULL)); 
    int numCities = 10, numToursInGeneration = 100, numGenerations = 100, mutationPercentage = 70;
    double gaResult, baResult;
    clock_t timer;
    float gaTime, baTime;

    std::cout << "Number of cities: ";
    std::cin >> numCities;
    std::cout << "Tours per generation: ";
    std::cin >> numToursInGeneration;
    std::cout << "Number of generations: ";
    std::cin >> numGenerations;
    std::cout << "Percentage of mutations per generation (0-100): ";
    std::cin >> mutationPercentage;

    DistMatrix dm("distances.txt");

    BruteAlg ba(dm);
    timer = clock();
    baResult = ba.run(numCities);
    baTime = float(clock() - timer) /  CLOCKS_PER_SEC;
   
    GeneticAlg ga(dm);
    timer = clock();
    gaResult = ga.run(numCities, numToursInGeneration, numGenerations, mutationPercentage);
    gaTime = float(clock() - timer) /  CLOCKS_PER_SEC;

    std::cout << "Number of cities run: " << numCities << std::endl;
    std::cout << "Optimal cost from brute force: " << baResult << std::endl;
    std::cout << "Time the brute force algorithm took: " << baTime << " s" << std::endl;
    std::cout << "Cost from the ga: " << gaResult << std::endl;
    std::cout << "Time the ga took to run: " << gaTime << " s" << std::endl;
    std::cout << "Percent of optimal that the ga produced: " << gaResult / baResult * 100 << "%" << std::endl;

    return 0;
};