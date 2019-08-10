all: baseballTest

baseball.o:
	g++ -c baseball.cc

baseballTest: baseball.o
	g++ baseball.o main.cpp -o baseballTest

cleanWindows:
	del baseball.o baseballTest.exe

clean:
	rm -f baseball.o baseballTest
