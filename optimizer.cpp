#include <iostream>
#include "optimizer.h"

using std::cout;

VectorXf Optimizer::StochasticGradientDescent::run(
    const VectorXf &predictions,
    const VectorXf &target,
    const float &learning_rate,
    const float &intercept,
    const VectorXf &coefficients)
{
    float new_intercept = intercept - learning_rate * (predictions - target).mean();
    VectorXf temp_coefficients = coefficients - (learning_rate * (target.transpose() * predictions)) / predictions.size();

    VectorXf new_coefficients = VectorXf(temp_coefficients.size() + 1);
    new_coefficients(0) = new_intercept;

    for (int i = 1; i < temp_coefficients.size(); i++)
    {
        new_coefficients(i) = temp_coefficients(i);
    }

    return new_coefficients;
}