#include <iostream>
#include "optimizer.h"

using std::cout;

Optimizer::StochasticGradientDescent::StochasticGradientDescent()
{
    cout << "Stochastic gradient descent" << "\n";
}

Optimizer::StochasticGradientDescent::~StochasticGradientDescent()
{
    cout << "Stochastic gradient descent has ended" << "\n";
}

void Optimizer::StochasticGradientDescent::backpropagate()
{
    return;
}