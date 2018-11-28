#pragma once
#include <vector>
#include <string>

struct stYieldCurveZeroCoupon 
{
	std::string AsOfDate;
	std::vector<double> Term; //in years
	std::vector<double> ZeroCouponRate; //real value

	stYieldCurveZeroCoupon() {};
	stYieldCurveZeroCoupon(const std::string& asOfDate,
		const std::vector<double>& term,
		const std::vector<double>& zeroCouponRate) :
		AsOfDate(asOfDate),
		Term(term),
		ZeroCouponRate(zeroCouponRate) {};
};
