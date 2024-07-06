#include "regression.h"
#include "optimizer.h"
#include "type.h"
#include "metrics.h"
#include <iostream>

using std::cout;
using std::string;

Regression::LinearRegression::LinearRegression()
{
    learning_rate = 0.01;
    iterations = 100;
    intercept = 0.0;
    metrics = "mse";
    optimizer = "sgd";
}

Regression::LinearRegression::LinearRegression(float learning_rate, int iterations, const string &metrics, const string &optimizer)
    : learning_rate(learning_rate), iterations(iterations), metrics(metrics), optimizer(optimizer)
{
}

void Regression::LinearRegression::fit(const MatrixXf &data, const VectorXf &target)
{
    for (int i = 0; i < Regression::LinearRegression::iterations; i++)
    {
        Regression::LinearRegression::optimize();
        cout << "Loss: " << Regression::LinearRegression::loss() << "\n";
    }
}

VectorXf Regression::LinearRegression::predict(const MatrixXf &data)
{
    VectorXf interceptVector = VectorXf::Constant(
        data.rows(),
        Regression::LinearRegression::intercept);

    return interceptVector + data * Regression::LinearRegression::coefficients;
}

const float Regression::LinearRegression::getIntercept()
{
    return Regression::LinearRegression::intercept;
}

const VectorXf Regression::LinearRegression::getCoefficients()
{
    return Regression::LinearRegression::coefficients;
}

void Regression::LinearRegression::optimize()
{
    vector<float> coefficients;

    VectorXf predictions = Regression::LinearRegression::predict(Regression::LinearRegression::data);
    if (Regression::LinearRegression::optimizer == "sgd")
    {
        VectorXf coefficients = Optimizer::StochasticGradientDescent::run(
            predictions,
            Regression::LinearRegression::target,
            Regression::LinearRegression::learning_rate,
            Regression::LinearRegression::intercept,
            Regression::LinearRegression::coefficients);
        Regression::LinearRegression::intercept = coefficients[0];
        Regression::LinearRegression::coefficients = VectorXf::Map(&coefficients[1], coefficients.size() - 1);
    }
}

float Regression::LinearRegression::loss()
{
    VectorXf predictions = Regression::LinearRegression::predict(Regression::LinearRegression::data);

    if (Regression::LinearRegression::metrics == "mse")
        return Metrics::MeanSquaredError::calculate(predictions, Regression::LinearRegression::target);

    if (Regression::LinearRegression::metrics == "mae")
        return Metrics::MeanAbsoluteError::calculate(predictions, Regression::LinearRegression::target);
}