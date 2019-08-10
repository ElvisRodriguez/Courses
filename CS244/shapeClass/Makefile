all: exe

shape.o:
	g++ -c shape.cc

rectangle.o:
	g++ -c rectangle.cc

circle.o:
	g++ -c circle.cc

triangle.o:
	g++ -c triangle.cc

exe: shape.o rectangle.o circle.o triangle.o
	g++ shape.o rectangle.o circle.o triangle.o main.cpp -o exe

clean:
	rm -f shape.o rectangle.o circle.o triangle.o exe
