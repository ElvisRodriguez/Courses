/*
//Name: Elvis Rodriguez
//Date: 2-26-18
//Question 2
*/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

bool eWff(string doi, bool (*func)(int));
bool isEven(int x);
bool isMult3(int x);

int main() {
  string files[2] = {"data1.txt", "data2.txt"};
  cout << boolalpha;
  for (int i = 0; i < 2; i++) {
    cout << "Predicate wff evaluates to " << eWff(files[i],isEven) << " for DOI " << (i +1)
         << " and predicate isEven()\n";
    cout << "Predicate wff evaluates to " << eWff(files[i],isMult3) << " for DOI " << (i + 1)
         << " and predicate isMult3()\n\n";
  }
  return 0;
}

bool eWff(string doi, bool (*func)(int)) {
  int value;
  string line;
  ifstream dataFile;
  dataFile.open(doi.c_str());
  if (dataFile.is_open()) {
    while (getline(dataFile, line)) {
      stringstream(line) >> value;
      if (func(value)) {
        return true;
      }
    }
  }
  dataFile.close();
  return false;
}

bool isEven(int x) {
  x = abs(x);
  if (x % 2 == 0) {
    return true;
  }
  return false;
}

bool isMult3(int x) {
  x = abs(x);
  if (x % 3 == 0) {
    return true;
  }
  return false;
}
