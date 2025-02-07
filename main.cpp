#include <iostream>
#include "subSystem.h"
#include "body.h"
#include "solarSystem.h"
#include "myVector.h"
#include "evolve.h"


using namespace std;

int main()
{
  // set up the solar system
  body earth;
  earth.setName("Earth").setMass(5.97e24);

  body moon;
  moon.setName("Moon").setMass(7.35e22);

  solarSystem earthMoon;

  myVector x(3);
  myVector v(3);
  x = v = {0., 0., 0.};
  earthMoon.add(&earth, x, v);
  x[0] = 384400000.;
  v[0] = 0.;
  v[1] = 1022.;
  earthMoon.add(&moon, x, v);
   
  // body sun;
  // sun.setName("Sun").setMass(1.9891e30);

  // solarSystem s;
  // x = v = {0., 0., 0.};
  // s.add(&sun, x, v);
  // x[1] = 1.496e11;
  // v[0] = -29.78e3;
  // s.add(&earthMoon, x, v);

  // prepare for the evolution
  double totalTime = 44192000, dt = 60, G = 6.67e-11;
  evolve myEvolution;
  myEvolution.setSystem(&earthMoon);
  myEvolution.setDt(dt);
  myEvolution.setG(G);
  int steps = (int) (totalTime/dt + 0.5);
  for (int i = 0; i < steps; i++)
    {
      myEvolution.evolution();
      if ((i % 10) == 0)
	{
	  cout << "T " << i * dt << " " << earth << endl;
	  cout << "T " << i * dt << " " << moon << endl;
	} 
    }
  

  
  return 9;
}
