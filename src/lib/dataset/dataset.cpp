#include <fstream>

#include "type.h"
#include "dataset.h"

using std::getline;
using std::string;

Dataset::Iris::Iris() : data(Dataset::Iris::row_size, Dataset::Iris::col_size), target(Dataset::Iris::row_size)
{
  file.open("iris.csv");
}

Dataset::Iris::~Iris()
{
  file.close();
}

void Dataset::Iris::load()
{
  float sepal_length;
  float sepal_width;
  float petal_length;
  float petal_width;
  float species;
  int index = 0;
  string line;

  while (getline(file, line))
  {
    Type::Iris iris;

    sscanf(
        line.c_str(),
        "%f,%f,%f,%f,%f",
        &iris.sepal_length,
        &iris.sepal_width,
        &iris.petal_length,
        &iris.petal_width,
        &iris.species);

    Dataset::Iris::data(index, 0) = iris.sepal_length;
    Dataset::Iris::data(index, 1) = iris.sepal_width;
    Dataset::Iris::data(index, 2) = iris.petal_length;
    Dataset::Iris::data(index, 3) = iris.petal_width;
    Dataset::Iris::target(index) = iris.species;
    index++;
  }
}

MatrixXf Dataset::Iris::getData()
{
  return Dataset::Iris::data;
}

RowVectorXf Dataset::Iris::getTarget()
{
  return Dataset::Iris::target;
}

vector<int> Dataset::Iris::getShape()
{
  vector<int> shape = {Dataset::Iris::row_size, Dataset::Iris::col_size};
  return shape;
}

Dataset::CalifornianHousing::CalifornianHousing() : data(Dataset::CalifornianHousing::row_size, Dataset::CalifornianHousing::col_size), target(Dataset::CalifornianHousing::row_size)
{
  file.open("california_housing.csv");
}

Dataset::CalifornianHousing::~CalifornianHousing()
{
  file.close();
}

void Dataset::CalifornianHousing::load()
{
  float median_income;
  float house_age;
  float average_rooms;
  float population;
  float average_occupancy;
  float latitude;
  float longitude;
  float median_house_value;
  int index = 0;
  string line;

  while (getline(file, line))
  {
    Type::CalifornianHousing californian_housing;
    float median_house_value;

    sscanf(
        line.c_str(),
        "%f,%f,%f,%f,%f,%f,%f,%f",
        &californian_housing.median_income,
        &californian_housing.house_age,
        &californian_housing.average_rooms,
        &californian_housing.population,
        &californian_housing.average_occupancy,
        &californian_housing.latitude,
        &californian_housing.longitude,
        &median_house_value);

    Dataset::CalifornianHousing::data(index, 0) = californian_housing.median_income;
    Dataset::CalifornianHousing::data(index, 1) = californian_housing.house_age;
    Dataset::CalifornianHousing::data(index, 2) = californian_housing.average_rooms;
    Dataset::CalifornianHousing::data(index, 3) = californian_housing.population;
    Dataset::CalifornianHousing::data(index, 4) = californian_housing.average_occupancy;
    Dataset::CalifornianHousing::data(index, 5) = californian_housing.latitude;
    Dataset::CalifornianHousing::data(index, 6) = californian_housing.longitude;
    Dataset::CalifornianHousing::target(index) = californian_housing.median_house_value;
    index++;
  }
}

MatrixXf Dataset::CalifornianHousing::getData()
{
  return Dataset::CalifornianHousing::data;
}

RowVectorXf Dataset::CalifornianHousing::getTarget()
{
  return Dataset::CalifornianHousing::target;
}

vector<int> Dataset::CalifornianHousing::getShape()
{
  vector<int> shape = {Dataset::CalifornianHousing::row_size, Dataset::CalifornianHousing::col_size};
  return shape;
}