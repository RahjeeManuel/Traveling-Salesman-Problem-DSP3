#ifndef DATAMATRIX_HPP
#define DATAMATRIX_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
class DataMatrix {
    private:
        double matrix[20][20];
    public:
        DataMatrix(std::string file);
        std::vector<int> getFirstPermutation(int size);
        std::vector<std::vector<int>> getElites(std::vector<std::vector<int>> s);
        std::vector<std::vector<int>> getMutations(std::vector<std::vector<int>> s, int n);
        std::vector<std::vector<int>> getPermutations(std::vector<int> p, int n);
        double getCost(std::vector<int> p);
        int factorial(int n);
};
#endif