#include <iostream>
#include "subSystem.h"
#include "body.h"
#include "solarSystem.h"
#include "myVector.h"
#include "evolve.h"
#include "integrator.h"

#include <fstream>
#include <math.h>

using namespace std;

void initialConditions(body *body, double dist, double vel, double obliquity);

int main()
{
  // set up the solar system
  // units for distance are kilometers

  myVector x(3);
  myVector v(3);

  list<ostream *>fileList;
  
  // sun
  solarSystem s;
  body sun;
  sun.setName("Sun").setMass(1.9891e30); 
  x = v = {0., 0., 0.};
  s.add(&sun, x, v);  

  
  // mercury
  body mercury;
  mercury.setName ("Mercury").setMass(3.302e23);
  x = {4.782259154868084e+07, -3.672923497533765e+07, -7.387919148774125e+06};
  v = {2.006519842075628e+01, 4.089619600131725e+01, 1.501695515387022e+00};
  s.add(&mercury, x, v);


  // venus
  body venus;
  venus.setName("Venus").setMass(48.685e23);
  x = {-4.652337254650509e+07, 9.683595418106040e+07, 4.014333765074775e+06};
  v = {-3.168408763342600e+01, -1.536135563096338e+01, 1.617217781828065e+00};
  s.add(&venus, x, v);

  
  // earth and moon 
  body earth;
  earth.setName("Earth").setMass(5.97e24);
  body moon;
  moon.setName("Moon").setMass(7.35e22);
  solarSystem earthMoon;
  x = v = {0., 0., 0.};
  earthMoon.add(&earth, x, v);
  x = {-1.371485473002827e+05, 3.547730789815042e+05, 2.999246319213205e+04};
  v = {-7.558313161693785e-01, -6.153080851335860e-01, 9.563751359323541e-02}; 
  earthMoon.add(&moon, x, v);
  x = {-1.149578512187004e+08, 9.260324321579321e+07, -4.984914915852249e+03};
  v = {-1.916041961341641e+01, -2.330534818006453e+01, 1.817466489818287e-03}; 
  s.add(&earthMoon, x, v);
  

  // mars
  body mars;
  mars.setName("Mars").setMass(6.4171e23);
  x = {-1.484585242147592e+08, 1.960659857296431e+08, 7.749379459287122e+06};
  v = {-1.840286598065266e+01, -1.256202198407803e+01, 1.880477911116154e-01};
  s.add(&mars, x, v);
  

  // jupiter
  body jupiter;
  jupiter.setName("Jupiter").setMass(18.9819e26);
  x = {1.129874607918700e+08, 7.538895800647380e+08, -5.659509278339028e+06};
  v = {-1.308474488420229e+01, 2.553469035115858e+00, 2.821915619099198e-01};
  s.add(&jupiter, x, v);
  

  // saturn
  body saturn;
  saturn.setName("Saturn").setMass(5.6834e26);
  x = {1.419222784859088e+09, -2.311500681781821e+08, -5.246804202066097e+07};
  v = {1.009181013303168e+00, 9.519413642561016e+00, -2.064156182382981e-01};
  s.add(&saturn, x, v);
  

  // uranus
  body uranus;
  uranus.setName("Uranus").setMass(86.813e24);
  x = {1.641436661340450e+09, 2.419910580493835e+09, -1.229602239493322e+07};
  v = {-5.699012782590723e+00, 3.510422517966965e+00, 8.691950056919073e-02};
  s.add(&uranus, x, v);
  
  
  // neptune 
  body neptune;
  neptune.setName("Neptune").setMass(102.409e24);
  x = {4.470168386022472e+09, -7.596051893732192e+07, -1.014470895454783e+08};
  v = {4.562887115927330e-02, 5.472499184038773e+00, -1.140518566783677e-01};
  s.add(&neptune, x, v);
  

  // pluto
  body pluto;
  pluto.setName("Pluto").setMass(1.307e22);
  x = {2.743495607005859e+09, -4.483488310502949e+09, -3.135296414841776e+08};
  v = {4.788323836190010e+00, 1.654313002967486e+00, -1.565936501666931e+00};
  s.add(&pluto, x, v);
  
 

  
  // prepare for the evolution
  long double totalTime = 1e10, dt = 30000, G = 6.67e-20;
  evolve myEvolution;
  RK2 I;
  myEvolution.setAlgorithm(&I).setSystem(&s).setDt(dt).setG(G);
  long int steps = (long int) (totalTime/dt + 0.5);
  cout << "# TotalSteps = " << steps << endl;
  list<body*> planets = s.getComponents();
  //  ofstream results("./simulazione.txt");
  
  myVector L0(3);
  L0 = s.getAngularMomentum();

  for (long int i = 0; i < steps; i++)
    {
      myEvolution.evolution();
      // if ((i % 100) == 0)
      // 	{
      // 	  list<body*>::iterator i2 = planets.begin();
      // 	  list<body*>::iterator e2 = planets.end();
      // 	  while (i2 != e2)
      // 	    {
      // 	      results << (*i2)->getName() << " ";
      // 	      results << (*i2)->getPosition()-sun.getPosition() << endl; 
      // 	      i2++;
      // 	    }
      // 	}
      if((i%500==0))
	{
	  cout << (L0 - s.getAngularMomentum()).norm()/L0.norm() << endl;
	}
    }
  

  
  return 9;
}

