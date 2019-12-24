all: humansTest

humans.o:
	g++ -c humans.cc

humansTest: humans.o
	g++ humans.o humans.cpp -o humansTest

clean:
	#del humans.o humansTest humansTest.exe
	rm -f humans.o humansTest
