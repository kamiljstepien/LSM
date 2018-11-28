#include "pch.h"
#include "../inc/LSMBuilder.h"

LSMBuilder::Builder LSMBuilder::getBuilder()
{
	return Builder();
}
LSMBuilder::Builder& LSMBuilder::Builder::setAmericanOption(const AmericanOption& AM)
{
	this->AM = AM;
	return *this;
}
LSMBuilder::Builder & LSMBuilder::Builder::setStockPaths(const std::vector<std::vector<double>>& StocPaths)
{
	if (StocPaths.size() == 0)
		throw std::exception(__FUNCTION__" StocPaths empty.");
	this->StocPaths = StocPaths;
	return *this;
}

LSMBuilder::Builder & LSMBuilder::Builder::setYieldCurveZeroCoupon(const stYieldCurveZeroCoupon & YieldCurveZeroCoupon)
{
	if (YieldCurveZeroCoupon.Term.size() == 0)
		throw std::exception(__FUNCTION__" Yield Curve empty.");
	this->YieldCurveZeroCoupon = YieldCurveZeroCoupon;
	return *this;
}

LSMBuilder LSMBuilder::Builder::build()
{
	//build vector of discount factors
	std::vector<double> discountFactors; //TODO

	//build vector of Stock Prices
	std::vector<std::vector<double>> StockPrices; //TODO

	//build vector of payOffs
	std::vector<std::vector<double>> PayOffs; //TODO

	return LSMBuilder(discountFactors, StockPrices, PayOffs);
}


double LSMBuilder::price()
{
	// TODO: tu wstawiæ instrukcjê
	return 0.0;
}




