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
        /////////// outputs matrix *temporary*
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        ///////////
    } else {
        std::cout << "Error opening " << file << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::vector<std::vector<int>> DataMatrix::getPermutations(std::vector<int> p, int n) {
    std::vector<std::vector<int>> s;
    for (int i = 0; i < n; i++) {
        s.push_back(p);
        std::next_permutation(p.begin(), p.end());
    }
    return s;
}
std::vector<int> DataMatrix::mutate(std::vector<int> p) {
    srand(time(NULL));
    std::vector<int> c(p);
    for (int i = 0; i < rand() % 4 + 1; i++) {
        std::swap(c[rand() % c.size()], c[rand() % c.size()]);
    }
    return c;
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