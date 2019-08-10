#include <iostream>
using namespace std;

#define SIZE 15
#define ROTATER 3

//Exercise 3
void nReverse(int num_array[], int n) {
  int temp_array[SIZE];
  n %= SIZE;
  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    temp_array[j] = num_array[i];
  }
  for (int i = 0; i < n; i++) {
    num_array[i] = temp_array[i];
  }
}

//Exercise 4
void arrayRotation(int numArray[]) {
  int coordinator = SIZE - ROTATER;
  int tempArray[SIZE];
  for (int i = coordinator, j = 0; j < SIZE; j++) {
    tempArray[j] = numArray[i];
    i++;
    i %= SIZE;
  }
  for (int i = 0; i < SIZE; i++) {
    numArray[i] = tempArray[i];
  }
}

int main() { 
  return 0;
}
