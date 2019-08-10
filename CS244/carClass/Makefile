all: carTest

car.o:
	g++ -std=c++11 -c car.cc

carTest: car.o
	g++ -std=c++11 car.o car.cpp -o carTest

clean:
	rm -f car.o carTest
