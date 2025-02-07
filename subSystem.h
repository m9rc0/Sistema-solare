#ifndef _SUBSYSTEM_H
#define _SUBSYSTEM_H

// this is just a simple abstract class for the composite pattern
#include <list>
#include "myVector.h"


class body;

class subSystem{
public:
  virtual subSystem& setPosition(const myVector &x) = 0;
  virtual subSystem& setVelocity(const myVector &v) = 0;
  virtual std::list<body *> getComponents() = 0;
};

#endif

