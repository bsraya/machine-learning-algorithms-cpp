#include "optimizer.h"

VectorXf Optimizer::StochasticGradientDescent::run(
    const RowVectorXf &predictions,
    const VectorXf &target,
    const float &learning_rate,
    const float &intercept,
    const VectorXf &coefficients)
{
    return VectorXf::Zero(1);
}