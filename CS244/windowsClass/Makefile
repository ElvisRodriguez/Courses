all: windowsTest

windows.o:
	gcc -c windows.cc

windowsTest: windows.o
	g++ windows.o main.cpp -o windowsTest

cleanWindows:
	del windows.o windowsTest.exe

clean:
	rm -f windows.o windowsTest
