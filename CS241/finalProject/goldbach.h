/*
//Name: Elvis Rodriguez
//Date: 5-10-18
//Description: The strong Goldbach’s conjecture states every even integer
               greater than or equal to 4 can be written as a sum of two primes.
               Write a program that shows that Goldbach’s conjecture is true for
               the even integers between 4 and 2000 inclusively. Store the sums
               in a file with each sum on its own line.
*/

#ifndef GOLDBACH_H
#define GOLDBACH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define SIZE 303 //Total Number of Primes below 2000

bool isPrime(int);
void allPrimes(int);
string findSum(int);
void writeConjectures();

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

void allPrimes(int emptyArray[]) {
  for (int i = 0, j = 2; j < 2000; j++) {
    if (isPrime(j)) {
      emptyArray[i] = j;
      i++;
    }
  }
}

string findSum(int x, int primes[]) {
  stringstream result;
  for (int i = 0; primes[i] < x; i++) {
    for (int j = 0; primes[j] < x; j++) {
      if (primes[i] + primes[j] == x) {
        result << x << " = " << primes[i] << " + " << primes[j] << endl;
        return result.str();
      }
    }
  }
}

void writeConjectures(int primes[]) {
  ofstream datafile("result.txt");
  if (datafile.is_open()) {
    datafile << "Goldbach Conjecture:\n";
    for (int i = 4; i <= 2000; i+=2) {
      datafile << findSum(i, primes);
    }
  }
  datafile.close();
}

#endif //GOLDBACH_H
