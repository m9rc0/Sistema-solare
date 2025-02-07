CXX = g++ -std=c++17

main.exe: main.o body.o solarSystem.o myVector.o evolve.o
	$(CXX) -o main.exe main.o body.o solarSystem.o myVector.o evolve.o
main.o: main.cpp myVector.h subSystem.h solarSystem.h body.h
	$(CXX) -c main.cpp
body.o: body.cc body.h subSystem.h myVector.h
	$(CXX) -c body.cc
solarSystem.o: solarSystem.cc solarSystem.h subSystem.h myVector.h
	$(CXX) -c solarSystem.cc
myVector.o: myVector.cc myVector.h
	$(CXX) -c myVector.cc
evolve.o: evolve.cc evolve.h solarSystem.h myVector.h body.h
	$(CXX) -c evolve.cc
clean:
	rm main.exe main.o body.o solarSystem.o myVector.o evolve.o
