all: bankAccountTest

bankAccount.o:
	g++ -c bankAccount.cc

bankAccountTest: bankAccount.o
	g++ -std=c++11 bankAccount.o bankAccount.cpp -o bankAccountTest

clean:
	rm -f bankAccountTest bankAccount.o
