#include "regression.h"
#include "type.h"
#include "dataset.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::string;
using std::vector;

int main()
{
  string metrics = "mse";
  string optimizer = "sgd";
  Regression::LinearRegression<vector<Type::Iris>, vector<float>> linear_regression(0.01, 10000, metrics, optimizer);

  Dataset::Iris iris;
  iris.load();

  vector<Type::Iris> X = iris.getData();
  vector<float> y = iris.getTarget();

  linear_regression.fit(X, y);
  linear_regression.getIntercept();
  linear_regression.getCoefficients();

  return 0;
}