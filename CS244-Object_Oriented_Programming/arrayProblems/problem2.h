/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Directive: Write a program that takes an integer array and prints out the
               sum of the even numbers. The array should have 15 integers.
*/

#include <iostream> //cout
#include <cstdlib> //srand(), rand()
#include <ctime> //time()
using namespace std;

#define SIZE 15

void generateRandomArray(int numArray[]) {
  srand(time(0));
  int randomNum;
  for (int i = 0; i < SIZE; i++) {
    randomNum = rand() % 100 + 1;
    numArray[i] = randomNum;
  }
}

void printOriginalArray(int numArray[]) {
  cout << "[";
  for (int i = 0; i < SIZE; i++) {
    if (i == SIZE - 1) {
      cout << numArray[i] << "]\n";
    } else {
        cout << numArray[i] << ", ";
    }
  }
}

void printSumEvenNumbers(int numArray[]) {
  int sum = 0;
  for (int i = 0; i < SIZE; i++) {
    if (numArray[i] % 2 == 0) {
      sum += numArray[i];
    }
  }
  cout << "Sum: " << sum << endl;
}
