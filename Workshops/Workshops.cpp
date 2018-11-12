// Workshops.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "inc/PolynomialRegression.h"
#include "inc/GBM.h"
#include "inc/Random.h"
#include "inc/AmericanOption.h"
#include "inc/LSM.h"

using namespace std;

int main()
{
	//sprawdzenie regresji
	double XList[5] = { 1.08,1.07, 0.97,0.77,0.84 };
	std::vector<double> X;
	X.insert(X.end(), XList, XList + 5);

	double YList[5] = { 0.0,0.0659232,0.1695168,0.188352,0.0847584 };
	std::vector<double> Y;
	Y.insert(Y.end(), YList, YList + 5);

	PolynomialRegression polReg;
	std::vector<double> coefficients(2);
	polReg.fitIt(X, Y, 2, coefficients);

	//sprawdzenie generatora
	double S0 = 1.0;
	double r = 0.06;
	double sigma = 0.2;
	double T = 3.0;
	int N = 4;
	Gaussian *gaussian = new GaussianBoxMuller();
	gaussian->setSeed(time(NULL));
	GBM pathGenerator(S0, sigma, r, *gaussian);
	std::vector<double> samplePath = pathGenerator.generateStockPath(T, N);

	//American Option
	double K = 1.1;
	AmericanOption AM(K, T, r);
	vector<double> samplePayoff = AM.payOff(samplePath);

	//sprawdzenie LSM
	vector< vector<double>> prices(8);
	prices[0] = { 1.0,1.09,1.08,1.34 };
	prices[1] = { 1.0,1.16,1.26,1.54 };
	prices[2] = { 1.0,1.22,1.07,1.03 };
	prices[3] = { 1.0,0.93,0.97,0.92 };
	prices[4] = { 1.0,1.11,1.56,1.52 };
	prices[5] = { 1.0,0.76,0.77,0.90 };
	prices[6] = { 1.0,0.92,0.84,1.01 };
	prices[7] = { 1.0,0.88,1.22,1.34 };
	LSM mc(AM, prices);
	cout << "LSM price: " << mc.price() << endl;


    std::cout << "Hello World!\n"; 
}