#ifndef DATAMATRIX_HPP
#define DATAMATRIX_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
class DataMatrix {
    private:
        double matrix[20][20];
    public:
        DataMatrix(std::string file);
        std::vector<std::vector<int>> getPermutations(std::vector<int> p, int n);
        std::vector<int> mutate(std::vector<int> p);
        double getCost(std::vector<int> p);   
};
#endif