all: exe

rational.o:
	g++ -c rational.cc

exe: rational.o
	g++ main.cpp rational.o -o exe

clean:
	rm -f rational.o exe
