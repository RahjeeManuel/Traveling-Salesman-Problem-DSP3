#ifndef GENETICALG_HPP
#define GENETICALG_HPP
#include "DistMatrix.hpp"
#include <vector>
class GeneticAlg {
    private:
        DistMatrix matrix;
        std::vector<std::vector<int>> getElites(std::vector<std::vector<int>> permutations);
        std::vector<std::vector<int>> getMutations(std::vector<std::vector<int>> permutations, int percent);
    public:
        GeneticAlg(DistMatrix matrix);
        double run(int numCities, int numToursInGeneration, int numGenerations, int mutationPercentage); 
};
#endif