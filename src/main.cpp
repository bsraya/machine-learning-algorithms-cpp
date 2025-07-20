// #include "lib/regression/regression.h"
// #include "lib/dataset/type.h"
// #include "lib/dataset/dataset.h"
// #include "lib/optimizer/optimizer.h"
// #include "lib/metrics/metrics.h"
// #include <chrono>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixX4f;
using Eigen::VectorXf;
using std::cout;
using std::string;
using std::vector;

// using namespace std::chrono;
#include <fmt/core.h>



// int main()
// {
//   Dataset::Iris iris;
//   iris.load();

//   vector<int> shape = iris.getShape();
//   MatrixXf X = iris.getData();
//   RowVectorXf y = iris.getTarget();

//   vector<int> iterations = {10, 100, 1000, 10000};

//   for (int iter : iterations)
//   {
//     auto start = high_resolution_clock::now();
//     Regression::LinearRegression linear_regression(0.01, iter, Metrics::Type::MSE, Optimizer::Type::SGD);
//     linear_regression.fit(X, y);
//     cout << "Intercept: " << linear_regression.getIntercept() << "\n";

//     cout << "Coefficients: ";
//     for (auto coef : linear_regression.getCoefficients())
//     {
//       cout << coef << " ";
//     }

//     cout << "\n";
//     auto end = high_resolution_clock::now();
//     auto duration = duration_cast<milliseconds>(end - start);

//     cout << "Training time: " << duration.count() << "ms\n";

//     cout << "\n\n";
//   }

//   return 0;
// }

int main() {
  Eigen::Matrix3d m = Eigen::Matrix3d::Random();
  Eigen::Vector3d v = Eigen::Vector3d::Random();
  
  fmt::print("Hello, World!\n");
  std::cout << "Matrix m:\n" << m << std::endl;
  std::cout << "Vector v:\n" << v << std::endl;
  std::cout << "m * v:\n" << m * v << std::endl;
  
  return 0;
}