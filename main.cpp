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
  Regression::LinearRegression linear_regression(0.01, 10000, "mse", "sgd");

  Dataset::Iris iris;
  iris.load();

  vector<int> shape = iris.getShape();
  MatrixXf X = iris.getData();
  VectorXf y = iris.getTarget();

  cout << "Shape: ";
  for (auto i : shape)
  {
    cout << i << " ";
  }

  // linear_regression.fit(X, y);
  // linear_regression.getIntercept();
  // linear_regression.getCoefficients();

  return 0;
}