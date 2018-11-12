#include "pch.h"
#include "../inc/GBM.h"
#include <cmath>

using namespace std;

tStockPath GBM::generateStockPath(double T, int numIntervals)
{
    tStockPath S(numIntervals+1,0.0);
    double dt = T/numIntervals;
    S[0] = this->_S0;
    std::vector<double> vdRandomNum = this->_Gaussian->generateVector(numIntervals);
    for(size_t k=1; k<S.size(); ++k){
        S[k]= S[k-1]*exp((_r-_Sigma*_Sigma*0.5)*dt+_Sigma*sqrt(dt)*vdRandomNum[k-1]);
    }
    return S;
}
