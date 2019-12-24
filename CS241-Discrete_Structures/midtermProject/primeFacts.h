/*
//Name: Elvis Rodriguez
//Date: 3-12-18
//Project type: Prime Factorization Calulator
*/

#ifndef PRIMEFACTS_H
#define PRIMEFACTS_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;

bool isPrime(int);
string exponentForm(int, int);
string primeFactorization(int);
void userProgram();
void printPrimeFactos(string);

/*
If σ(n) equals the sum of n’s factors and τ(n) equals the count of n’s factors,
then:

(a) if n = p is prime, what is σ(n) and τ(n)?
    σ(n) = n + 1, τ(n) = 2
(b) if n = pq where p and q are both prime, what is σ(n) and τ(n)?
    σ(n) = (p + 1)(q + 1), τ(n) = 4
(c) if n = p^m where p is prime and m > 1, what is σ(n) and τ(n)?
    σ(n) = (p^m + p^m-1 + .. + p^2 + p) + 1, τ(n) = m + 1
*/

bool isPrime(int x) {
  if (x <= 1) {
    return false;
  } else if (x == 2 || x == 3) {
    return true;
  } else {
    for (int i = 2; i < x; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  }
}

string exponentForm(int numArray[], int size) {
  stringstream result;
  int counter = 1;
  for (int i = 1; i < size; i++) {
    if (numArray[i] == numArray[i-1]) {
      counter++;
    }
    else {
      result << "(" << numArray[i - 1] << "^" << counter << ")";
      counter = 1;
    }
  }
  return result.str();
}

string primeFactorization(int x) {
  stringstream result;
  int numArray[100] = {0}; //Bulat wanted to try this alternative solution
  int count = 0;
  while (x % 2 == 0) {
    numArray[count] = 2;
    count++;
    x /= 2;
  }
  for (int i = 3; i <= sqrt(x); i += 2) {
    while (x % i == 0) {
      numArray[count] = i;
      count++;
      x /= i;
    }
  }
  if (x > 2) {
    numArray[count] = x;
    count++;
  }
  //numArray[count] = 1;
  count += 1;
  result << exponentForm(numArray, count);
  return result.str();
}

void userProgram() {
  int input = 1;
  cout << "Prime Factorization Calulator\n";
  while (input != 0) {
    cout << "Enter a number greater than 1\nEnter 0 to quit: ";
    cin >> input;
    if (input == 0) {
      return;
    } else if (input == 1) {
      cout << "Input must be greater than 1\n";
    }
    cout << primeFactorization(input) << endl;
    if (isPrime(input)) {
      cout << "(This number is prime)\n";
    }
  }
}

void printPrimeFactos(string filename) {
  ofstream datafile;
  datafile.open(filename);
  string temp2;
  string temp = primeFactorization(27);
  if (datafile.is_open()) {
    datafile << "Prime Factorization of:\n";
    for (int i = 2; i <= 1000; i++) {
      datafile << i << ": ";
      datafile << primeFactorization(i) << endl;
    }
  }
  datafile.close();
}

#endif //PRIMEFACTS_H
