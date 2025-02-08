#ifndef _BODY_H
#define _BODY_H

#include "subSystem.h"
#include "myVector.h"
#include "integrator.h"
#include <string>
#include <iostream>

class integrator;

class body : public subSystem
{
private:
  myVector _x;
  myVector _v;
  std::string _name;
  double _mass;
public:
  body(): _x(3), _v(3){
    _x = 0.;
    _v = 0.;
  }
  ~body() = default; 
  body& setName(std::string name);
  body& setMass(double mass);
  body& setPosition(const myVector &x);
  body& setVelocity(const myVector &v);
  std::list<body *> getComponents();
  std::string getName();
  double getMass();
  myVector getPosition();
  myVector getVelocity();
  body& move(integrator *I);

  // operators
  friend std::ostream& operator<<(std::ostream &o, const body &corpo);
  body& operator=(const body &b);
};

#endif
