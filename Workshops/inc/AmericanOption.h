#pragma once
#include <vector>

class AmericanOption{
public:
    AmericanOption(double K, double T, double r):
        _K(K),
        _T(T),
        _r(r){};
    std::vector<double> payOff(const std::vector<double>& stockPath) const;
	double getExpiry() const { return _T; }
	double getRiskFreeRate() const { return _r; }
private:
    double _K;
    double _T; //in years
    double _r; //?
} ;
