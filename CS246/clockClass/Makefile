all: clockTest

clock.o:
	g++ -c clock.cc

clockTest: clock.o
	g++ clock.o main.cpp -o clockTest

clean:
	del clock.o clockTest.exe

clean2:
	rm -f clock.o clockTest
