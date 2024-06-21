#include <vector>
#include "optimizer.h"

namespace Optimizer
{
  std::vector<float> batchGradientDescent()
  {
    std::vector<float> vec;

    for (int i = 1; i <= 5; i++)
    {
      // convert `i` to float
      vec.push_back(i * 1.0);
    }

    return vec;
  }

  std::vector<float> miniBatchGradientDescent()
  {
    std::vector<float> vec;

    for (int i = 1; i <= 5; i++)
    {
      vec.push_back(i * 1.0);
    }

    return vec;
  }

  std::vector<float> stochasticGradientDescent()
  {
    std::vector<float> vec;

    for (int i = 1; i <= 5; i++)
    {
      vec.push_back(i * 1.0);
    }

    return vec;
  }
}