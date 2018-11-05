#include "../inc/GBM.h"
#include <cmath>

using namespace std;

tStockPath GBM::generateStockPath(double T, int numIntervals)
{
    tStockPath S(numIntervals,0.0);
    double dt = T/numIntervals;
    double St = this->_S0;
    std::vector<double> vdRandomNum = this->_Gaussian->generateVector(numIntervals);
    for(int k=0; k<numIntervals; ++k){
        S[k]= St*exp((_r-_Sigma*_Sigma*0.5)*dt+_Sigma*sqrt(dt)*vdRandomNum[k]);
        St=S[k];
    }
    return S;
}
