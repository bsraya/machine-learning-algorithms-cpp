#ifndef DATASET_H
#define DATASET_H

#include <fstream>
#include <vector>

using std::ifstream;
using std::vector;

namespace Dataset
{
  class Iris
  {
  public:
    vector<Type::Iris> data;
    vector<float> target;
    ifstream file;

    Iris();
    ~Iris();

    void load();
    vector<Type::Iris> getData();
    vector<float> getTarget();
  };

  class CalifornianHousing
  {
  public:
    vector<Type::CalifornianHousing> data;
    vector<float> target;
    ifstream file;

    CalifornianHousing();
    ~CalifornianHousing();

    void load();
  };
}

#endif // DATASET_H