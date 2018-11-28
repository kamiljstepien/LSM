#pragma once
#include <vector>
#include <exception>
#include <random>
#include <map>

//Gaussian Random Number Generation
class Gaussian{
public:
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
class GaussianCpp11 : public Gaussian
{
public:
	GaussianCpp11() {
		_Mean = 0.0;
		_SqrtVariance = 0.0;
		_distribution = std::normal_distribution<double>(_Mean, _SqrtVariance);
	};
	virtual void setSeed(int s);
	virtual double generate(void);
	virtual std::vector<double> generateVector(int N);//N - dimension
	~GaussianCpp11() {};
private:
	std::normal_distribution<double> _distribution;
};

enum GaussianRandomGenerators 
{
	BoxNuller,
	InverseCDF,
	Cpp11Generator
};

class GaussianStrategyPattern
{
public:
	GaussianStrategyPattern()
	{
		_Strategies[GaussianRandomGenerators::BoxNuller] = new GaussianBoxMuller();
		_Strategies[GaussianRandomGenerators::Cpp11Generator] = new GaussianCpp11();
	}
private:
	std::map< GaussianRandomGenerators, Gaussian*> _Strategies;
};
