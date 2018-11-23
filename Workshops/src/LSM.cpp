#include "pch.h"
#include "../inc/LSM.h"
#include "../inc/PolynomialRegression.h"
#include <algorithm>

using namespace std;

LSM::LSM(const AmericanOption& AM, const std::vector<std::vector<double>>& StocPaths) :_AM(AM)
{
	//first time step is t=0
	this->_StockPriceStep.resize(StocPaths[0].size());//no calculate payoff of first step which is t=0
	for (size_t i = 0; i < _StockPriceStep.size(); ++i)
	{
		_StockPriceStep[i].resize(StocPaths.size());
		for (size_t j = 0; j < _StockPriceStep[i].size(); ++j)
			_StockPriceStep[i][j] = StocPaths[j][i];
	}
	_StockPriceStep.erase(_StockPriceStep.begin());
	this->_AMPayoffStep.resize(_StockPriceStep.size());
	for (size_t i = 0; i < _AMPayoffStep.size(); ++i)
		_AMPayoffStep[i] = _AM.payOffPut(_StockPriceStep[i]);
}
double LSM::price()
{
	size_t NSteps = _AMPayoffStep.size();
	double timeInterval = _AM.getExpiry() / (double)NSteps;
	double discountFactor = exp(-1.0* _AM.getRiskFreeRate() *timeInterval);
	vector<vector<int>> controlMatrix(NSteps,vector<int>(_AMPayoffStep[0].size()));
	for (size_t i = NSteps-1; 0 < i; --i)
	{
		vector<double> AMPayoffITM_discounted;
		vector<double> StockPriceITM;
		vector<size_t> PathNumber;
		for (size_t j = 0; j < _AMPayoffStep[i].size(); ++j)
			if (_AMPayoffStep[i-1][j] > 0) {//only paths in the money
				AMPayoffITM_discounted.push_back(_AMPayoffStep[i][j] * discountFactor);
				StockPriceITM.push_back(_StockPriceStep[i - 1][j]);
				PathNumber.push_back(j);
			}
		vector<double> coefficients;
		PolynomialRegression PR;
		PR.fitIt(StockPriceITM, AMPayoffITM_discounted, 2, coefficients);
		for (size_t j = 0; j < StockPriceITM.size(); ++j)
		{
			double stockPrice = StockPriceITM[j];
			double expectedPayoff = coefficients[0] + coefficients[1] * stockPrice + coefficients[2] * stockPrice*stockPrice;
			double whatPayoff = _AMPayoffStep[i - 1][PathNumber[j]];
			if (_AMPayoffStep[i - 1][PathNumber[j]] > expectedPayoff) {
				controlMatrix[i - 1][PathNumber[j]] = 1;
				controlMatrix[i][PathNumber[j]] = 0;
			}
			else if(_AMPayoffStep[i][PathNumber[j]])//no put 1 next to 0 payoff
				controlMatrix[i][PathNumber[j]] = 1;
		}
	}
	vector<double> discountedCashFlows(_AMPayoffStep[0].size());
	for(size_t i=0; i< controlMatrix.size();++i){ //iteration through time steps
		for (size_t j = 0; j < controlMatrix[i].size(); ++j) {//iteration through paths
			if (controlMatrix[i][j] == 1)
				discountedCashFlows[j] = _AMPayoffStep[i][j] * pow(discountFactor, i);
		}
	}
	//averaging 
	double MCPrice=0.0;
	for (size_t i = 0; i < discountedCashFlows.size(); ++i)
		MCPrice = ((double)i*MCPrice + discountedCashFlows[i]) / (i + 1.0);
	return MCPrice;
}