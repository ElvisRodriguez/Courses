#ifndef HEXCONVER_H
#define HEXCONVER_H

#include <iostream>
#include <string>
#include <stack>
using namespace std;

//Hexadecimal characters
//012345678ABCDEF

char intToHex(int n) {
  char hexNums[15] = {
    '0', '1', '2', '3', '4',
    '5', '6', '7', '8', 'A',
    'B', 'C', 'D', 'E', 'F'
  };
  return hexNums[n%16];
}

string numToHexadecimal(int num) {
  stack<char> dataStore;
  string result = "";
  while (num != 0) {
    dataStore.push(intToHex(num%16));
    num /= 16;
  }
  while (!dataStore.empty()) {
    result += dataStore.top();
    dataStore.pop();
  }
  return result;
}


#endif //HEXCONVER_H
