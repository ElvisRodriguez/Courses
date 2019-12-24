all: circleTest

circle.o:
	g++ -c circle.cc

circleTest: circle.o
	g++ circle.o circle.cpp -o circleTest

clean:
	rm -f circle.o circleTest
