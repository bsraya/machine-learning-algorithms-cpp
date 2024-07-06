#include "metrics.h"

float Metrics::MeanSquaredError::calculate(const VectorXf &predictions, const VectorXf &target)
{
    return (predictions - target).squaredNorm() / predictions.size();
}

float Metrics::MeanAbsoluteError::calculate(const VectorXf &predictions, const VectorXf &target)
{
    return 0.1;
}