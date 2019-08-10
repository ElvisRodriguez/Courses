all: pointTest

point.o:
	g++ -c point.cc

pointTest: point.o
	g++ point.o point.cpp -o pointTest

clean:
	rm -f point.o pointTest
