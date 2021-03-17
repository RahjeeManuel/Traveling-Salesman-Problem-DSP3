#include "InputHandler.hpp"
InputHandler::InputHandler() {
    std::cout << "Number of cities: ";
    std::cin >> numCities;
    std::cout << "Tours per generation: ";
    std::cin >> numToursInGeneration;
    std::cout << "Number of generations: ";
    std::cin >> numGenerations;
    std::cout << "Percentage of mutations per generation (0-100): ";
    std::cin >> mutationPercentage;
}
int InputHandler::getNumCities() {
    return numCities;
}
int InputHandler::getNumToursInGeneration() {
    return numToursInGeneration;
}
int InputHandler::getNumGenerations() {
    return numGenerations;
}
int InputHandler::getMutationPercentage() {
    return mutationPercentage;
}