#pragma once
#include <vector>

class AmericanOption{
public:
	AmericanOption() {};//konstruktor domyœlny

    AmericanOption(double K, double T, double r):
        _K(K),
        _T(T),
        _r(r){};
    std::vector<double> payOffPut(const std::vector<double>& stockPath) const;
	double payOffPut(double stockPrice) const;

	//getters
	double getExpiry() const { return _T; }
	double getRiskFreeRate() const { return _r; }
	double getStrikePrice() const { return _K; }
private:
    double _K;
    double _T; //in years
    double _r; //?
} ;
