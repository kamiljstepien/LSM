#pragma once
#include "../inc/AmericanOption.h"
#include "../inc/YieldCuve.h"

class LSMBuilder {
public:
	class Builder {
	public:
		Builder() {};
		Builder& setAmericanOption(const AmericanOption& AM);
		Builder& setStockPaths(const std::vector<std::vector<double>>& StocPaths);
		Builder& setYieldCurveZeroCoupon(const stYieldCurveZeroCoupon& YieldCurveZeroCoupon);
		LSMBuilder build();
	private:
		AmericanOption AM;
		std::vector<std::vector<double>> StocPaths;
		stYieldCurveZeroCoupon YieldCurveZeroCoupon;
	};
	static Builder getBuilder();
	double price();
private:
	std::vector<double> _DiscountFactors;
	std::vector<std::vector<double>> _StockPriceStep;
	std::vector<std::vector<double>> _AMPayoffStep;

	LSMBuilder(const std::vector<double>& discountFactors,
		const std::vector<std::vector<double>>& stocPriceStep,
		const std::vector<std::vector<double>>& AMPayoffStep) :
		_DiscountFactors(discountFactors),
		_StockPriceStep(stocPriceStep),
		_AMPayoffStep(AMPayoffStep) {};
};