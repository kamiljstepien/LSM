#include "pch.h"
#include "../inc/AmericanOption.h"
#include <algorithm>

using namespace std;

std::vector<double> AmericanOption::payOffPut(const std::vector<double>& stockPath) const
{
    std::vector<double> results(stockPath.size(),0.0);
    for(size_t i=0; i<stockPath.size(); ++i){
        if(stockPath[i]<this->_K)
            results[i]=this->_K - stockPath[i];
        else
           results[i]= 0.0;
        //results[i] = std::max(this->_K - stockPath[i],0.0);
    }
    return results;
}
double AmericanOption::payOffPut(double stockPrice) const
{
	return max(this->_K - stockPrice, 0.0);
}
