/*
    Si definiscono la classe myVector e i suoi metodi
*/

#ifndef MYVECTOR
#define MYVECTOR

#include <vector>

class myVector
{
private:
  int dim;
  std::vector<double> x;
public:
  myVector(){}
  myVector(int n);
  myVector(std::vector<double> vec);
  
  // operator overload
  myVector &operator=(const myVector &vec);
  myVector &operator=(std::vector<double> vec) ;
  myVector &operator=(double vec);  
  
  // sum and subtraction between vectors
  myVector operator+(const myVector &vec) const;
  myVector& operator+=(const myVector &vec);
  myVector operator-(const myVector &vec) const;
  
  // multiplication and division by scalar
  myVector operator*(double lambda) const;
  myVector operator/(double lambda) const;
  myVector &operator*=(double lambda);
  myVector &operator/=(double lambda);

  double operator[](int i) const {return x[i];};
  double& operator[](int i) {return x[i];};

  friend  std::ostream& operator<<(std::ostream &o, const myVector &vec);
  
  // methods
  int getDimension() const;
  double getComponent(int i) const;
  double norm();
};


#endif
