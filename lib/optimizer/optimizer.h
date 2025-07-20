#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <Eigen/Dense>
#include <vector>

using Eigen::MatrixXf;
using Eigen::RowVectorXf;
using Eigen::VectorXf;
using std::vector;

namespace Optimizer
{
  enum Type
  {
    BGD,
    MBGD,
    SGD,
    ADAGRAD,
    ADADELTA,
    ADAM,
  };

  class StochasticGradientDescent
  {
  public:
    static VectorXf run(
        const RowVectorXf &predictions,
        const VectorXf &target,
        const float &learning_rate,
        const float &intercept,
        const VectorXf &coefficients);
  };
}

#endif // OPTIMIZER_H