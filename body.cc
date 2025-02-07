#include "body.h"

body& body::setName(std::string name)
{
  _name = name;
  return *this;
}

/******************************/

body& body::setMass(double mass)
{
  _mass = mass;
  return *this;
}

/******************************/

body& body::setPosition(const myVector &x)
{
  // con il più così ogni volta che si fanno composizioni di sistemi si aggiorna la posizione
  _x = _x + x;
  return *this;
}

/******************************/

body& body::setVelocity(const myVector &v)
{
  
  // con il più così ogni volta che si fanno composizioni di sistemi si aggiorna la posizione
  _v = _v + v;
  return *this;
}

/******************************/

std::list<body *> body::getComponents()
{
  std::list<body *> l;
  l.push_back(this);
  return l;
}

/******************************/

std::string body::getName()
{
  return _name;
}

/******************************/

double body::getMass()
{
  return _mass;
}

/******************************/

myVector body::getPosition()
{
  return _x;
}

/******************************/

myVector body::getVelocity()
{
  return _v;
}

/******************************/

body& body::move(const myVector &F, double dt)
{
  _v += (F/_mass)*dt;
  _x += _v*dt;
  return *this;
}

/******************************/

std::ostream& operator<<(std::ostream &o, const body &corpo)
{
  std::cout << corpo._name << " " << corpo._x << corpo._v;
  return o;
}

/******************************/
