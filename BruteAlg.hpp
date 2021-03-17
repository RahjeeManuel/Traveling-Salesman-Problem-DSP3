#ifndef BRUTEALG_HPP
#define BRUTEALG_HPP
#include "DistMatrix.hpp"
#include <vector>
class BruteAlg {
    private:
        DistMatrix matrix;
        int factorial(int num);
    public:
        BruteAlg(DistMatrix matrix);
        double run(int numCities);
};
#endif