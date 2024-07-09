#include "regression.h"
#include "type.h"
#include "dataset.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Eigen/Dense>

using Eigen::MatrixX4f;
using Eigen::VectorXf;
using std::cout;
using std::string;
using std::vector;

int main()
{
  Regression::LinearRegression linear_regression(0.01, 1000, "mae", "sgd");

  Dataset::Iris iris;
  iris.load();

  vector<int> shape = iris.getShape();
  MatrixXf X = iris.getData();
  RowVectorXf y = iris.getTarget();

  linear_regression.fit(X, y);
  cout << "Intercept: " << linear_regression.getIntercept() << "\n";

  cout << "Coefficients: ";
  for (auto coef : linear_regression.getCoefficients())
  {
    cout << coef << " ";
  }

  return 0;
}