#include <fstream>

#include "type.h"
#include "dataset.h"

using std::string;

Dataset::Iris::Iris()
{
  file.open("iris.csv");
}

Dataset::Iris::~Iris()
{
  file.close();
}

void Dataset::Iris::load()
{
  string line;

  while (std::getline(file, line))
  {
    Type::Iris iris;
    float species;

    sscanf(
        line.c_str(),
        "%f,%f,%f,%f,%f",
        &iris.sepal_length,
        &iris.sepal_width,
        &iris.petal_length,
        &iris.petal_width,
        &species);

    data.push_back(iris);
    target.push_back(species);
  }
}

vector<Type::Iris> Dataset::Iris::getData()
{
  return Dataset::Iris::data;
}

vector<float> Dataset::Iris::getTarget()
{
  return Dataset::Iris::target;
}

Dataset::CalifornianHousing::CalifornianHousing()
{
  file.open("boston_housing.csv");
}

Dataset::CalifornianHousing::~CalifornianHousing()
{
  file.close();
}

void Dataset::CalifornianHousing::load()
{
  string line;

  while (std::getline(file, line))
  {
    Type::CalifornianHousing housing;
    float price;

    sscanf(
        line.c_str(),
        "%f,%f,%f,%f,%f,%f,%f,%f",
        &housing.median_income,
        &housing.house_age,
        &housing.average_rooms,
        &housing.population,
        &housing.average_occupancy,
        &housing.latitude,
        &housing.longitude,
        &price);

    data.push_back(housing);
    target.push_back(price);
  }
}