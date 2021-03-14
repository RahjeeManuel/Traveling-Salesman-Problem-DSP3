#include "DataMatrix.hpp"
#include <iostream>

int main() {
    int numCities, numToursInGeneration, numGenerations, mutationPercentage;
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
    return 0;
};