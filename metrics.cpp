#include "metrics.h"

float Metrics::MeanSquaredError::calculate(const VectorXf &predictions, const VectorXf &target)
{
    const int predictions_length = predictions.size();
    const int target_length = target.size();

    if (predictions_length != target_length)
    {
        throw std::invalid_argument("The length of the predictions and target vectors must be equal.");
    }

    return (predictions - target).squaredNorm() / predictions.size();
}

float Metrics::MeanAbsoluteError::calculate(const VectorXf &predictions, const VectorXf &target)
{
    const int predictions_length = predictions.size();
    const int target_length = target.size();

    if (predictions_length != target_length)
    {
        throw std::invalid_argument("The length of the predictions and target vectors must be equal.");
    }

    return (predictions - target).array().abs().sum() / predictions.size();
}