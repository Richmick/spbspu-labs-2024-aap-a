#include "count_saddle_point.hpp"

namespace kushekbaev
{
  int & getElement(int * matrix, size_t columns, size_t row, size_t column);
  bool isMinInRow(int* matrix, size_t columns, size_t row, int element);
  bool isMaxInColumn(int* matrix, size_t rows, size_t columns, size_t column, int element);
}

int & kushekbaev::getElement(int * matrix, size_t columns, size_t row, size_t column)
{
  return matrix[row * columns + column];
}

bool kushekbaev::isMinInRow(int* matrix, size_t columns, size_t row, int element)
{
  for (size_t z = 0; z < columns; z++)
  {
    if (getElement(matrix, columns, row, z) < element)
    {
      return false;
    }
  }
  return true;
}

bool kushekbaev::isMaxInColumn(int* matrix, size_t rows, size_t columns, size_t column, int element)
{
  for (size_t z = 0; z < rows; z++)
  {
    if (getElement(matrix, columns, z, column) > element)
    {
      return false;
    }
  }
  return true;
}

int kushekbaev::countSaddlePoints(int * matrix, size_t rows, size_t columns)
{
  int count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      int element = getElement(matrix, columns, i, j);

      if (isMinInRow(matrix, columns, i, element) && isMaxInColumn(matrix, rows, columns, j, element))
      {
        count++;
      }
    }
  }
return count;
