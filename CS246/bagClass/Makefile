all: bagTest

bag.o:
	g++ -c bag.cc

bagTest: bag.o
	g++ bag.o bag.cpp -o bagTest

clean:
	rm -f bag.o bagTest
