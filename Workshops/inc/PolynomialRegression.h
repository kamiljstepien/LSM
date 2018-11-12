#pragma once

#include<vector>

class PolynomialRegression {
  public:

    PolynomialRegression();
    virtual ~PolynomialRegression(){};

    bool fitIt(
      const std::vector<double> & x,
      const std::vector<double> & y,
      const int &             order,
      std::vector<double> &     coeffs);
};
