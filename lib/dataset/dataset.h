#ifndef DATASET_H
#define DATASET_H

#include <fstream>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixX4f;
using Eigen::MatrixXf;
using Eigen::RowVectorXf;
using std::ifstream;
using std::vector;

namespace Dataset
{
  class DatasetBase{
  public:
    virtual ~DatasetBase() = default;

    virtual void load() = 0;
    virtual vector<int> getShape() = 0;
    virtual MatrixXf getData() = 0;
    virtual RowVectorXf getTarget() = 0;
  };

  class Iris: public DatasetBase
  {
  public:
    const int row_size = 150;
    const int col_size = 4;
    MatrixXf data;
    RowVectorXf target;
    ifstream file;

    Iris();
    ~Iris();

    void load();
    vector<int> getShape();
    MatrixXf getData();
    RowVectorXf getTarget();
    MatrixXf describe();
  };

  class CalifornianHousing: public DatasetBase
  {
  public:
    const int row_size = 20640;
    const int col_size = 7;
    MatrixXf data;
    RowVectorXf target;
    ifstream file;

    CalifornianHousing();
    ~CalifornianHousing();

    void load();
    vector<int> getShape();
    MatrixXf getData();
    RowVectorXf getTarget();
  };
}

#endif // DATASET_H