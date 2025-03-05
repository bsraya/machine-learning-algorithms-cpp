#ifndef METRICS_H
#define METRICS_H

#include <Eigen/Dense>

using Eigen::VectorXf;

namespace Metrics
{
    enum Type
    {
        MSE,
        MAE,
        RMSE,
        F1,
    };

    class MeanSquaredError
    {
    public:
        static float calculate(const VectorXf &predictions, const VectorXf &target);
    };

    class MeanAbsoluteError
    {
    public:
        static float calculate(const VectorXf &predictions, const VectorXf &target);
    };

    class RootMeanSquaredError
    {
    public:
        static float calculate(const VectorXf &predictions, const VectorXf &target);
    };
}

#endif // METRICS_H