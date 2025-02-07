#include "myVector.h"
#include <iostream>
#include <math.h>

/*       CONSTRUCTORS       */

/*********************************/

myVector::myVector(std::vector<double> vec)
{
    dim = vec.size();
    x = vec;
}

/*********************************/

myVector::myVector(int n)
{
    dim = n;
    for (int i = 0; i < dim; i++)
    {
        x.push_back(0);
    }
}

/*********************************/

/*      OPERATORS OVERLOAD      */

myVector &myVector::operator=(const myVector &vec)
{
    dim = vec.dim;
    x = vec.x;
    return *this;
}

/*********************************/

myVector &myVector::operator=(std::vector<double> vec)
{
    dim = vec.size();
    x = vec;
    return *this;
}

/*********************************/

myVector &myVector::operator=(double vec)
{
  for(int i = 0; i < dim; i++)
    {
      x[i] = vec;
    }
  return *this;
}

/*********************************/

std::ostream& operator<<(std::ostream &o, const myVector &vec)
{
  for (int i = 0; i < vec.getDimension(); i++)
    {
      o << vec[i] << " ";
    }
  return o;
}

/**********************************/


myVector myVector::operator+(const myVector &vec) const 
{
  if (dim != vec.dim)
    {
      std::cout << "Vectors need to have the same dimension!\n";
        exit(-1);
    }
    myVector scratch(dim);
    for (int i = 0; i < dim; i++)
    {
        scratch.x[i] = x[i] + vec.x[i];
    }
    return scratch;
}

/*********************************/

myVector myVector::operator-(const myVector &vec) const
{
    if (dim != vec.dim)
    {
      std::cout << "Vectors need to have the same dimension";
        exit(-1);
    }
    myVector scratch(dim);
    for (int i = 0; i < dim; i++)
    {
        scratch.x[i] = x[i] - vec.x[i];
    }
    return scratch;
}
/*********************************/

myVector myVector::operator*(double lambda) const
{
    myVector scratch(dim);
    for (int i = 0; i < dim; i++)
    {
        scratch.x[i] = lambda * x[i];
    }
    return scratch;
}

/*********************************/

myVector myVector::operator/(double lambda) const
{
    myVector scratch(dim);
    for (int i = 0; i < dim; i++)
    {
        scratch.x[i] = x[i] / lambda;
    }
    return scratch;
}

/*********************************/

myVector &myVector::operator*=(double lambda)
{
    for (int i = 0; i < dim; i++)
    {
        x[i] *= lambda;
    }
    return *this;
}

/*********************************/

myVector &myVector::operator/=(double lambda)
{
    for (int i = 0; i < dim; i++)
    {
        x[i] /= lambda;
    }
    return *this;
}

/*********************************/

myVector& myVector::operator+=(const myVector &vec)
{
  if (dim != vec.dim)
    {
      std::cout << "Vectors need to have the same dimension!\n";
      exit(-1);
    }
  for (int i = 0; i < dim; i++)
    {
      x[i] += vec.x[i];
    }
  return *this;
}


/*          METHODS         */

/*******************************/

int myVector::getDimension() const
{
    return dim;
}

/*******************************/

double myVector::getComponent(int i) const
{
    if ((i < 0) || (i >= dim))
    {
      std::cout << "error with dimensions\n";
        exit(-1);
    }
    return x[i];
}

/*******************************/

double myVector::norm()
{
  double norm = 0;
  for (int i = 0; i < dim; i++)
    {
      norm += x[i]*x[i];
    }
  return sqrt(norm);
}
