#include <fstream>

#include "type.h"
#include "dataset.h"

using std::string;

Dataset::Iris::Iris() : data(Dataset::Iris::row_size, Dataset::Iris::col_size), target(Dataset::Iris::row_size)
{
}

void Dataset::Iris::load()
{
  float sepal_length;
  float sepal_width;
  float petal_length;
  float petal_width;
  float species;
  int index = 0;

  io::CSVReader<5> in("iris.csv");
  in.read_header(
      io::ignore_extra_column,
      "sepal_length",
      "sepal_width",
      "petal_length",
      "petal_width",
      "species");

  while (in.read_row(sepal_length, sepal_width, petal_length, petal_width, species))
  {
    Dataset::Iris::data(index, 0) = sepal_length;
    Dataset::Iris::data(index, 1) = sepal_width;
    Dataset::Iris::data(index, 2) = petal_length;
    Dataset::Iris::data(index, 3) = petal_width;
    Dataset::Iris::target(index) = species;
    index++;
  }
}

MatrixXf Dataset::Iris::getData()
{
  return Dataset::Iris::data;
}

VectorXf Dataset::Iris::getTarget()
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

  io::CSVReader<8> in("california_housing.csv");
  in.read_header(
      io::ignore_extra_column,
      "median_income",
      "house_age",
      "average_rooms",
      "population",
      "average_occupancy",
      "latitude",
      "longitude",
      "median_house_value");

  while (in.read_row(median_income, house_age, average_rooms, population, average_occupancy, latitude, longitude, median_house_value))
  {
    Dataset::CalifornianHousing::data(index, 0) = median_income;
    Dataset::CalifornianHousing::data(index, 1) = house_age;
    Dataset::CalifornianHousing::data(index, 2) = average_rooms;
    Dataset::CalifornianHousing::data(index, 3) = population;
    Dataset::CalifornianHousing::data(index, 4) = average_occupancy;
    Dataset::CalifornianHousing::data(index, 5) = latitude;
    Dataset::CalifornianHousing::data(index, 6) = longitude;
    Dataset::CalifornianHousing::target(index) = median_house_value;

    index++;
  }
}

MatrixXf Dataset::CalifornianHousing::getData()
{
  return Dataset::CalifornianHousing::data;
}

VectorXf Dataset::CalifornianHousing::getTarget()
{
  return Dataset::CalifornianHousing::target;
}

vector<int> Dataset::CalifornianHousing::getShape()
{
  vector<int> shape = {Dataset::CalifornianHousing::row_size, Dataset::CalifornianHousing::col_size};
  return shape;
}