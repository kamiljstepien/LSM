#pragma once
#include <vector>

class AmericanOption{
public:
    AmericanOption(double K, double T, double r):
        _K(K),
        _T(T),
        _r(r){};
    std::vector<double> payOff(const std::vector<double>& stockPath) const;
private:
    double _K;
    double _T; //in years
    double _r; //?
} ;
