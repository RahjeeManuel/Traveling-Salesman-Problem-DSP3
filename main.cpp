#include "InputHandler.hpp"
#include "DistMatrix.hpp"
#include "BruteAlg.hpp"
#include "GeneticAlg.hpp"
#include <iostream>
int main() {

    //load distances.txt
    DistMatrix dm("distances.txt");

    //get user input
    InputHandler input;

    //run brute algorithm
    BruteAlg ba(dm);
    double baResult = ba.run(input);
   
    //run generic algorithm
    GeneticAlg ga(dm);
    double gaResult = ga.run(input);

    //print optimal percentage
    std::cout << "Percent of optimal that the ga produced: " << gaResult / baResult * 100 << "%" << std::endl;

    return 0;
};