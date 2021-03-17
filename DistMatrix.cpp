#include "DistMatrix.hpp"
DistMatrix::DistMatrix() {
    DistMatrix("distances.txt");
}
DistMatrix::DistMatrix(std::string fileName) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == j) {
                    distances[i][j] = 0;
                } else {
                    inFile >> distances[i][j];
                }
            }
        }
        inFile.close();
    } else {
        exit(EXIT_FAILURE);
    }
}
std::vector<int> DistMatrix::getFirstPermutation(int size) {
    std::vector<int> permutation;
    for (int i = 0; i < size; i++) {
        permutation.push_back(i + 1);
    }
    return permutation;
}
std::vector<std::vector<int>> DistMatrix::getNextPermutations(std::vector<int> permutation, int amount) {
    std::vector<std::vector<int>> nextPermutations;
    for (int i = 0; i < amount; i++) {
        nextPermutations.push_back(permutation);
        std::next_permutation(permutation.begin(), permutation.end());
    }
    return nextPermutations;
}
double DistMatrix::getTotalDist(std::vector<int> permutation) {
    double totalDist = 0;
    permutation.insert(permutation.begin(), 0);
    permutation.push_back(0);
    for (int i = 0; i < permutation.size() - 1; i++) {
        totalDist += distances[permutation[i]][permutation[i + 1]];
    }
    return totalDist;
}