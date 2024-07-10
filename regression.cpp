#include "regression.h"
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
    metrics = Metrics::Type::MSE;
    optimizer = Optimizer::Type::SGD;
}

Regression::LinearRegression::LinearRegression(float learning_rate, int iterations, Metrics::Type metrics, Optimizer::Type optimizer)
    : learning_rate(learning_rate), iterations(iterations), metrics(metrics), optimizer(optimizer)
{
}

void Regression::LinearRegression::fit(const MatrixXf &data, const RowVectorXf &target)
{
    Regression::LinearRegression::data = data;
    Regression::LinearRegression::target = target;
    Regression::LinearRegression::intercept = 0.0;
    Regression::LinearRegression::coefficients = RowVectorXf::Zero(data.cols());

    for (int i = 0; i < Regression::LinearRegression::iterations; i++)
    {
        Regression::LinearRegression::optimize();
        // cout << "(Iteration " << i << ") " << "Loss: " << Regression::LinearRegression::loss(data) << "\n";
    }
}

RowVectorXf Regression::LinearRegression::predict(const MatrixXf &data)
{
    RowVectorXf predictions = data * Regression::LinearRegression::coefficients.transpose();
    RowVectorXf interceptVector = RowVectorXf::Constant(data.rows(), Regression::LinearRegression::intercept);
    return interceptVector + predictions;
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
    const int length = Regression::LinearRegression::data.rows();
    RowVectorXf predictions = predict(Regression::LinearRegression::data);
    RowVectorXf error = predictions - Regression::LinearRegression::target;

    Regression::LinearRegression::intercept = Regression::LinearRegression::intercept -
                                              (Regression::LinearRegression::learning_rate * error.sum() / length);

    RowVectorXf coef_error_vector = Regression::LinearRegression::data.transpose() * error.transpose();
    Regression::LinearRegression::coefficients = Regression::LinearRegression::coefficients -
                                                 (Regression::LinearRegression::learning_rate * coef_error_vector / length);
    // cout << "Intercept: " << Regression::LinearRegression::intercept << "\n";
    // cout << "Coefficients: " << Regression::LinearRegression::coefficients << "\n\n";
}

float Regression::LinearRegression::loss(const MatrixXf &data)
{
    if (Regression::LinearRegression::metrics == Metrics::Type::MSE)
        return Metrics::MeanSquaredError::calculate(Regression::LinearRegression::predict(data), Regression::LinearRegression::target);

    if (Regression::LinearRegression::metrics == Metrics::Type::MAE)
        return Metrics::MeanAbsoluteError::calculate(Regression::LinearRegression::predict(data), Regression::LinearRegression::target);

    if (Regression::LinearRegression::metrics == Metrics::Type::RMSE)
        return Metrics::RootMeanSquaredError::calculate(Regression::LinearRegression::predict(data), Regression::LinearRegression::target);
}