/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Directive: Write a program that checks an array of temperatures and prints
             out the number of temperatures greater than 70. The array should
             have 14 temperatures.
*/

#include "problem3.h"

int main() {
  cout << "Problem 3:\n";
  int temperatures[SIZE] = {0};
  generateTemperatures(temperatures);
  printTemperatureArray(temperatures);
  printNumOfTempsAbove70(temperatures);

  return 0;
}
