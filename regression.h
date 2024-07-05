#ifndef REGRESSION_H
#define REGRESSION_H
#include <string>
#include <Eigen/Dense>
#include <vector>

using Eigen::MatrixX4f;
using Eigen::RowVectorXf;
using Eigen::Vector4f;
using Eigen::VectorXf;
using std::string;
using std::vector;

namespace Regression
{
  template <typename T1, typename T2>
  class LinearRegression
  {
  private:
    T1 data;
    T2 target;
    void optimize(string optimizer, MatrixX4f X, VectorXf y);
    float loss(string metrics);

  public:
    float learning_rate = 0.01;
    int iterations = 100;
    float intercept = 0.0;
    string metrics = "mse";
    string optimizer = "sgd";
    Vector4f coefficients = Vector4f::Zero();

    LinearRegression(float learning_rate, int iterations, string metrics, string optimizer);
    ~LinearRegression();
    void fit(T1 data, T2 target);
    RowVectorXf predict(float intercept, Vector4f coefficients, MatrixX4f features);

    float getIntercept();
    Vector4f getCoefficients();
  };
}

#endif // REGRESSION_H