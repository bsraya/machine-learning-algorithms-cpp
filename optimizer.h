#ifndef OPTIMIZER_H
#define OPTIMIZER_H

namespace Optimizer
{
  class StochasticGradientDescent
  {
  public:
    StochasticGradientDescent();
    ~StochasticGradientDescent();
    void backpropagate();
  };
}

#endif // OPTIMIZER_H