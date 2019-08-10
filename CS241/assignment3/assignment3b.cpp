/*
//Name: Elvis Rodriguez
//Date: 3-5-18
//Question 4
*/

#include <iostream>
#include <fstream>
#include <string>
//#include <sstream>
using namespace std;

#define SIZE 500

bool inArray(int numArray[], int num, int currentSize) {
  for (int i = 0; i < currentSize; i++) {
    if (num == numArray[i]) {
      return true;
    }
  }
  return false;
}

bool isSet(string filename) {
  int value, i = 0;
  int valuesArray[SIZE];
  string line;
  ifstream dataFile;
  dataFile.open(filename);//.c_str()
  if (dataFile.is_open()) {
    while (getline(dataFile, line)) {
      //stringstream(line) >> value;
      value = stoi(line);
      if (inArray(valuesArray, value, i)) {
        return false;
      } else {
        valuesArray[i] = value;
        i++;
      }
    }
  }
  dataFile.close();
  return true;
}

int main() {
  string data[2] = {"data1.txt", "data2.txt"};
  for (int i = 0; i < 2; i++) {
    cout << data[i] << (isSet(data[i])?(" does"):(" does not")) << " represent a set\n";
  }
  return 0;
}
