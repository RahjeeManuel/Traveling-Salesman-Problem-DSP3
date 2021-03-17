#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include <iostream>
class InputHandler {
    private:
        int numCities;
        int numToursInGeneration;
        int numGenerations;
        int mutationPercentage;
    public:
        InputHandler();
        int getNumCities();
        int getNumToursInGeneration();
        int getNumGenerations();
        int getMutationPercentage();
};
#endif