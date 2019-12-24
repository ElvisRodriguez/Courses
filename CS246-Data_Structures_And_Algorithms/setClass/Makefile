all: setTest

sets.o:
	g++ -c sets.cc

setTest: sets.o
	g++ sets.o main.cpp -o setTest

clean:
	rm -f sets.o setTest
