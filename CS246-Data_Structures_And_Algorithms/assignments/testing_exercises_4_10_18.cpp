#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 10

template <class T>
int inArray(T array[], int currentSize, T value) {
  for (int i = 0; i < currentSize; i++) {
    if (value == array[i]) {
      return i;
    }
  }
  return -1;
}

T maximum(T valueA, T valueB) {
  if (valueA > valueB) {
    return valueA;
  }
  return valueB;
}


int main() {
  srand(time(0));

  int testArray[SIZE];

  for (int i = 0; i < (SIZE / 2); i++) {
    testArray[i] = rand() % 10 + 1;
  }

  char testArray2[SIZE];
  char j = 'a';
  for (int i = 0, j = 'a'; i < (SIZE/2); i++, j++) {
    testArray2[i] = j;
  }

  cout << "inArray() test for integers:\n";
  cout << "Testing for 3:\n";
  cout << "position: " << inArray(testArray, (SIZE/2), 3) << endl;
  cout << "Testing for 6:\n";
  cout << "position: " << inArray(testArray, (SIZE/2), 6) << endl;
  cout << "Testing for 8:\n";
  cout << "position: " << inArray(testArray, (SIZE/2), 8) << endl;

  cout << "inArray() test for characters:\n";
  cout << "Trying for character c (should pass):\n";
  cout << inArray(testArray2, (SIZE/2), 'c') << endl;
  cout << "Trying for character h (should fail):\n";
  cout << inArray(testArray2, (SIZE/2), 'h') << endl;

  cout << "maximum() test:\n";
  cout << "Maximum of integers (4,10):\n";
  cout << maximum(4,10) << endl;
  cout << "Maximum of doubles (3.67, 8.76):\n";
  cout << maximum(3.67, 8.76) << endl;

  return 0;
}
