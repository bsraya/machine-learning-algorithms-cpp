#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>

namespace Optimizer
{
  std::vector<float> batchGradientDescent();
  std::vector<float> miniBatchGradientDescent();
  std::vector<float> stochasticGradientDescent();
}

#endif // OPTIMIZER_H