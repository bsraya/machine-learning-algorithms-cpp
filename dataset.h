#ifndef DATASET_H
#define DATASET_H

#include <fstream>
#include <vector>
#include <Eigen/Dense>
#include "csv.h"

using Eigen::MatrixXf;
using Eigen::VectorXf;
using std::ifstream;
using std::vector;

namespace Dataset
{
  class Iris
  {
  public:
    const int row_size = 150;
    const int col_size = 5;
    MatrixXf data;
    VectorXf target;

    Iris();

    void load();
    vector<int> getShape();
    MatrixXf getData();
    VectorXf getTarget();
  };

  class CalifornianHousing
  {
  public:
    const int row_size = 20640;
    const int col_size = 8;
    MatrixXf data;
    VectorXf target;

    CalifornianHousing();

    void load();
    vector<int> getShape();
    MatrixXf getData();
    VectorXf getTarget();
  };
}

#endif // DATASET_H