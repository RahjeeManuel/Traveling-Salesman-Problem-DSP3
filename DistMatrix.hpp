#ifndef DATAMATRIX_HPP
#define DATAMATRIX_HPP
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
class DistMatrix {
    private:
        double distances[20][20];
    public:
        DistMatrix(); 
        DistMatrix(std::string fileName);
        std::vector<int> getFirstPermutation(int size);
        std::vector<std::vector<int>> getNextPermutations(std::vector<int> permutation, int amount);
        double getTotalDist(std::vector<int> permutation);
};
#endif