#include "DataMatrix.hpp"
DataMatrix::DataMatrix(std::string file) {
    std::ifstream inFile(file);
    if (inFile.is_open()) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == j) {
                    matrix[i][j] = 0;
                } else {
                    inFile >> matrix[i][j];
                }
            }
        }
        inFile.close();
    } else {
        std::cout << "Error opening " << file << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::vector<int> DataMatrix::getFirstPermutation(int size) {
    std::vector<int> s;
    for (int i = 0; i < size; i++) {
        s.push_back(i + 1);
    }
    return s;
}
std::vector<std::vector<int>> DataMatrix::getElites(std::vector<std::vector<int>> s) {
    std::vector<std::vector<int>> p;
    std::vector<int> first(s[0]), second(s[1]);
    for (int i = 0; i < s.size(); i++) {
        if (getCost(s[i]) < getCost(first)) {    
            second = first;
            first = s[i];
        } else if (getCost(s[i]) < getCost(second) && s[i] != first) {
            second = s[i];
        }
    }
    p.push_back(first);
    p.push_back(second);
    return p;
}
std::vector<std::vector<int>> DataMatrix::getMutations(std::vector<std::vector<int>> s, int n) {
    srand(time(NULL));
    std::vector<std::vector<int>> m;
    std::vector<int> p;
    for (int i = 0; i < s.size() * ((double) n / 100.00); i++) {
        p = s[rand() % (s.size() - 1)]; // mutate random tour
        //p = s[0]; // mutate first elite
        for (int j = 0; j < rand() % 4 + 1; j++) {
            std::swap(p[rand() % p.size()], p[rand() % p.size()]);    
        }
        m.push_back(p);
    }
    return m;
}
std::vector<std::vector<int>> DataMatrix::getPermutations(std::vector<int> p, int n) {
    std::vector<std::vector<int>> s;
    for (int i = 0; i < n; i++) {
        s.push_back(p);
        std::next_permutation(p.begin(), p.end());
    }
    return s;
}
double DataMatrix::getCost(std::vector<int> p) {  
    p.insert(p.begin(), 0);
    p.push_back(0);
    double cost = 0;
    for (int i = 0; i < p.size() - 1; i++) {
        cost += matrix[p[i]][p[i+1]];
    }
    return cost;
}