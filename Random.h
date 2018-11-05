#pragma once
#include <vector>
#include <exception>

//Gaussian Random Number Generation
class Gaussian{
public:
    //Gaussian():_Mean(0.0), _SqrtVariance(1.0){};
    //Gaussian(double mean, double sqrtVariance):_Mean(mean), _SqrtVariance(sqrtVariance){};
    virtual void setSeed(int s) = 0; //seed of rand() generator
    virtual double generate(void) = 0;
    virtual std::vector<double> generateVector(int N) = 0;//N - dimension
    virtual ~Gaussian(){};
protected:
    double _Mean;
    double _SqrtVariance;
};
class GaussianBoxMuller: public Gaussian
{
public:
    GaussianBoxMuller(){
        _Mean=0.0;
        _SqrtVariance=0.0;
    };
    virtual void setSeed(int s);
    virtual double generate(void);
    virtual std::vector<double> generateVector(int N);//N - dimension
    ~GaussianBoxMuller(){};
} ;
