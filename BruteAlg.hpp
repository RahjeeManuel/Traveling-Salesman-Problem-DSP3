#ifndef BRUTEALG_HPP
#define BRUTEALG_HPP
#include "DistMatrix.hpp"
#include "InputHandler.hpp"
#include <vector>
#include <time.h>
#include <iostream>
class BruteAlg {
    private:
        DistMatrix matrix;
        int factorial(int num);
    public:
        BruteAlg(DistMatrix matrix);
        double run(InputHandler input);
};
#endif