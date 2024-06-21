#include <vector>
#include <iostream>
#include "optimizer.h"

int main()
{
  std::vector<float> vec;
  vec = Optimizer::batchGradientDescent();

  for (auto i : vec)
  {
    std::cout << i << '\n';
  }

  std::cout << "Hello, World!" << '\n';

  return 0;
}