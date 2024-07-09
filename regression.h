#ifndef REGRESSION_H
#define REGRESSION_H
#include <Eigen/Dense>
#include <string>
#include <vector>

using Eigen::MatrixXf;
using Eigen::RowVectorXf;
using Eigen::Vector4f;
using Eigen::VectorXf;
using std::string;
using std::vector;

namespace Regression
{
  class LinearRegression
  {
  public:
    float learning_rate;
    int iterations;
    string metrics;
    string optimizer;

    float intercept;
    RowVectorXf coefficients;
    MatrixXf data;
    RowVectorXf target;

    LinearRegression();

    LinearRegression(
        float learning_rate,
        int iterations,
        const string &metrics,
        const string &optimizer);

    void fit(const MatrixXf &data, const RowVectorXf &target);
    void optimize();

    RowVectorXf predict(const MatrixXf &data);
    const float getIntercept();
    const VectorXf getCoefficients();
    float loss(const MatrixXf &data);
  };
}

#endif // REGRESSION_H