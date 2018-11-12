#pragma once
#include <vector>
#include "../inc/Random.h"
typedef std::vector<double> tStockPath;

class GBM
{
public:
    GBM(double S0, double sigma, double r, Gaussian& gaussian):
        _S0(S0),
        _Sigma(sigma),
        _r(r),
        _Gaussian(&gaussian){};
    tStockPath generateStockPath(double T, int numIntervals);
    ~GBM(){delete _Gaussian;};
private:
    double _S0;
    double _Sigma;
    double _r;
    Gaussian* _Gaussian;
};
