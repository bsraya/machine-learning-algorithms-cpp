#include "regression.h"
#include "optimizer.h"
#include "type.h"
#include "metrics.h"
#include <iostream>

using std::cout;

template <typename T1, typename T2>
Regression::LinearRegression<T1, T2>::LinearRegression(float learning_rate, int iterations, string metrics, string optimizer)
    : learning_rate(learning_rate), iterations(iterations), metrics(metrics), optimizer(optimizer)
{
}

template <typename T1, typename T2>
Regression::LinearRegression<T1, T2>::~LinearRegression()
{
}

template <typename T1, typename T2>
void Regression::LinearRegression<T1, T2>::fit(T1 data, T2 target)
{
    int y = 0;
    for (auto i : data)
    {
        if (y == 5)
            break;
        cout << i.sepal_length << "," << i.sepal_width << "," << i.petal_length << "," << i.petal_width << "\n";
        ++y;
    }

    y = 0;
    for (auto t : target)
    {
        if (y == 5)
            break;
        cout << t << "\n";
        ++y;
    }
    // int row_size = flowers.size();
    // int col_size = sizeof(flowers[0]) / sizeof(float);
    // MatrixX4f X(row_size, col_size);
    // VectorXf y(row_size);

    // for (int i = 0; i < row_size; i++)
    // {
    //     X(i, 0) = flowers[i].sepal_length;
    //     X(i, 1) = flowers[i].sepal_width;
    //     X(i, 2) = flowers[i].petal_length;
    //     X(i, 3) = flowers[i].petal_width;
    // }

    // Regression::LinearRegression::optimize(Regression::LinearRegression::optimizer, X, y);
}

template <typename T1, typename T2>
RowVectorXf Regression::LinearRegression<T1, T2>::predict(float intercept, Vector4f coefficients, MatrixX4f features)
{
    return RowVectorXf::Zero();
}

template <typename T1, typename T2>
float Regression::LinearRegression<T1, T2>::getIntercept()
{
    return Regression::LinearRegression<T1, T2>::intercept;
}

template <typename T1, typename T2>
Vector4f Regression::LinearRegression<T1, T2>::getCoefficients()
{
    return Regression::LinearRegression<T1, T2>::coefficients;
}

template <typename T1, typename T2>
void Regression::LinearRegression<T1, T2>::optimize(string optimizer, MatrixX4f X, VectorXf y)
{
    if (optimizer == "sgd")
    {
        Optimizer::StochasticGradientDescent sgd;
        sgd.backpropagate();
    }
}

template <typename T1, typename T2>
float Regression::LinearRegression<T1, T2>::loss(string metrics)
{
    if (metrics == "mse")
    {
        return Metrics::MeanSquaredError::calculate();
    }

    if (metrics == "mae")
    {
        return Metrics::MeanAbsoluteError::calculate();
    }

    return Metrics::MeanAbsoluteError::calculate();
}