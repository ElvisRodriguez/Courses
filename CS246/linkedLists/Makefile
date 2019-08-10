all: listTest

llists.o:
	g++ -c llists.cc

listTest: llists.o
	g++ llists.o main.cpp -o listTest

clean:
	rm -f llists.o listTest

cleanW:
	del llists.o listTest.exe
