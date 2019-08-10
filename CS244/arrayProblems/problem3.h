/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Directive: Write a program that checks an array of temperatures and prints
             out the number of temperatures greater than 70. The array should
             have 14 temperatures.
*/

#include <iostream> //cout
#include <cstdlib> //srand(), rand()
#include <ctime> //time()
using namespace std;

#define SIZE 14

void generateTemperatures(int temperatureArray[]) {
  srand(time(0));
  int randomTemperature;
  for (int i = 0; i < SIZE; i++) {
    randomTemperature = rand() % 213; //Goes from 0 degrees to water's boiling point
    temperatureArray[i] = randomTemperature;
  }
}

void printTemperatureArray(int temperatureArray[]) {
  cout << "[";
  for (int i = 0; i < SIZE; i++) {
    if (i == SIZE - 1) {
      cout << temperatureArray[i] << "]\n";
    } else {
        cout << temperatureArray[i] << ", ";
    }
  }
}

void printNumOfTempsAbove70(int temperatureArray[]) {
  int count = 0;
  for (int i = 0; i < SIZE; i++) {
    if (temperatureArray[i] > 70) {
      count++;
    }
  }
  cout << "There are " << count << " temperatures above 70\n";
}
