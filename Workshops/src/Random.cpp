#include "pch.h"
#include "../inc/Random.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const static double pi=4.0*atan(1.0);

void GaussianBoxMuller::setSeed(int s){
    srand(s);
}
double GaussianBoxMuller::generate(void)
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}
std::vector<double> GaussianBoxMuller::generateVector(int N)
{
    int i =0;
    vector<double> results(N);
    while (i<N){
        results[i] = this->generate();
		++i;
    }
    return results;
}
void GaussianCpp11::setSeed(int s)
{
	std::default_random_engine generator(s);
}
double GaussianCpp11::generate(void)
{
	std::default_random_engine gen((int)time(NULL));
	return _distribution(gen);
}
std::vector<double> GaussianCpp11::generateVector(int N)
{
	int i = 0;
	vector<double> results(N);
	while (i < N) {
		results[i] = this->generate();
		++i;
	}
	return results;
}
