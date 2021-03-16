#include "DataMatrix.hpp"
DataMatrix::DataMatrix(std::string file) {
    std::ifstream inFile(file);
    //read file and place each distance into a new matrix index
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
        //close the program if the program fails to open the file
        std::cout << "Error opening " << file << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::vector<int> DataMatrix::getFirstPermutation(int size) {
    std::vector<int> s;
    for (int i = 0; i < size; i++) {    //generates the first permutation of a tour with n size "1 2 3 4 5"
        s.push_back(i + 1);
    }
    return s;
}

std::vector<std::vector<int>> DataMatrix::getElites(std::vector<std::vector<int>> s) {
    std::vector<std::vector<int>> p;
    std::vector<int> first(s[0]), second(s[1]);
    for (int i = 0; i < s.size(); i++) {
        if (getCost(s[i]) < getCost(first)) {      //if the current tour is better than the first, it is now the first and the previous first is now second
            second = first;
            first = s[i];
        } else if (getCost(s[i]) < getCost(second) && s[i] != first) {  //if the current tour is not better than the first but better than the second and is not the first then it is now the second best tour
            second = s[i];
        }
    }
    p.push_back(first);
    p.push_back(second); 
    return p;
}

std::vector<std::vector<int>> DataMatrix::getMutations(std::vector<std::vector<int>> s, int n) {
    std::vector<std::vector<int>> m;
    std::vector<int> p;
    if (n > 100) {  //if n is greater than (100)% clamp it to 100
        n = 100;
    }
    srand(time(NULL));
    for (int i = 0; i < (s.size() - 2) * ((double) n / 100.00); i++) { //loop n% number of times with mutatable tours (generation.size() - (# of elites))
        p = s[rand() % 4];      //mutate one of the first four tours
        for (int j = 0; j < rand() % 2 + 1; j++) {  //swap 1 or 2 times
            std::swap(p[rand() % p.size()], p[rand() % p.size()]);    //swap random numbers
        }
        m.push_back(p);
    }
    return m;
}

std::vector<std::vector<int>> DataMatrix::getPermutations(std::vector<int> p, int n) {
    std::vector<std::vector<int>> s;
    for (int i = 0; i < n; i++) {
        s.push_back(p);
        std::next_permutation(p.begin(), p.end());  //permutation loop n number of times
    }
    return s;
}

double DataMatrix::getCost(std::vector<int> p) {
    double cost = 0;
    p.insert(p.begin(), 0);     //add 0 to both ends of the tour => 1 2 3 4 becomes 0 1 2 3 4 0
    p.push_back(0);
    for (int i = 0; i < p.size() - 1; i++) {    //compute distance cost with the "new" tour
        cost += matrix[p[i]][p[i + 1]];
    }
    return cost;
}

int DataMatrix::factorial(int n) {  //find factorial of a number (used to find number of permutations in brute algorithm)
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}