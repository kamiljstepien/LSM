#pragma once
#include "../inc/AmericanOption.h"
#include <vector>

class LSM {
public:
	LSM(const AmericanOption& AM, const std::vector<std::vector<double>>& StocPaths);
	double price();
private:
	AmericanOption _AM;
	std::vector<std::vector<double>> _StockPriceStep;
	std::vector<std::vector<double>> _AMPayoffStep;
};

