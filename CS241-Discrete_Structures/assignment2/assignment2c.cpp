/*
//Name: Elvis Rodriguez
//Date: 2-26-18
//Question 5
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool uWff(string doi, bool (*func)(int));
bool isOdd(int x);
bool isMult5(int x);

int main() {
  string files[2] = {"data1.txt", "data2.txt"};
  cout << boolalpha;
  for (int i = 0; i < 2; i++) {
    cout << "Predicate wff evaluates to " << uWff(files[i], isOdd) << " for DOI " << (i + 1)
         << " and predicate isOdd()\n";
    cout << "Predicate wff evaluates to " << uWff(files[i], isMult5) << " for DOI " << (i + 1)
         << " and predicate isMult5()\n\n";
  }
 return 0;
}

bool uWff(string doi, bool (*func)(int)) {
  int value;
  string line;
  ifstream dataFile;
  dataFile.open(doi.c_str());
  if (dataFile.is_open()) {
    while (getline(dataFile, line)) {
      stringstream(line) >> value;
      if (func(value) == false) {
        return false;
      }
    }
  }
  dataFile.close();
  return true;
}

bool isOdd(int x) {
  x = abs(x);
  if (x % 2 == 0) {
    return false;
  }
  return true;
}

bool isMult5(int x) {
  x = abs(x);
  if (x % 5 == 0) {
    return true;
  }
  return false;
}
