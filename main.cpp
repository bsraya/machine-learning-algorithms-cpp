#include "regression.h"
#include "type.h"
#include "dataset.h"
#include "optimizer.h"
#include "metrics.h"
#include <chrono>
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

using namespace std::chrono;

int main()
{
  Dataset::Iris iris;
  iris.load();

  vector<int> shape = iris.getShape();
  MatrixXf X = iris.getData();
  RowVectorXf y = iris.getTarget();

  vector<int> iterations = {10, 100, 1000, 10000, 100000, 1000000};

  for (int iter : iterations)
  {
    auto start = high_resolution_clock::now();
    Regression::LinearRegression linear_regression(0.01, iter, Metrics::Type::MSE, Optimizer::Type::SGD);
    linear_regression.fit(X, y);
    cout << "Intercept: " << linear_regression.getIntercept() << "\n";

    cout << "Coefficients: ";
    for (auto coef : linear_regression.getCoefficients())
    {
      cout << coef << " ";
    }

    cout << "\n";
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Training time: " << duration.count() << "ms\n";

    cout << "\n\n";
  }

  return 0;
}