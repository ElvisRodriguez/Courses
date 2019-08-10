/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Directive: Write a program that takes an integer array and prints out the
               sum of the even numbers. The array should have 15 integers.
*/

#include "problem2.h"

int main() {
  cout << "Problem 2: \n";
  int numArray[SIZE];
  generateRandomArray(numArray);
  printOriginalArray(numArray);
  printSumEvenNumbers(numArray);

  return 0;
}
