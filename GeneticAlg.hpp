#ifndef GENETICALG_HPP
#define GENETICALG_HPP
#include "DistMatrix.hpp"
#include "InputHandler.hpp"
#include <vector>
#include <iostream>
#include <time.h>
class GeneticAlg {
    private:
        DistMatrix matrix;
        std::vector<std::vector<int>> getElites(std::vector<std::vector<int>> permutations);
        std::vector<std::vector<int>> getMutations(std::vector<std::vector<int>> permutations, int percent);
    public:
        GeneticAlg(DistMatrix matrix);
        double run(InputHandler input); 
};
#endif