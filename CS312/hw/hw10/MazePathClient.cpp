#include <iostream>
#include <string>

using namespace std;

#include "MazePath.h"

//Checks if user input is valid to avoid raising MazePath class assertion
//error and instead inform user their input is invalid with the option to cont.
bool validInput(string& input) {
  string validChars = "NSEW";
  for (int i = 0 ; i < input.length(); i++) {
    input[i] = toupper(input[i]);
    if (validChars.find(input[i]) == string::npos) {
      return false;
    }
  }
  return true;
}

int main() {
  char another = 'y';
  string path = "";
  MazePath mazepath;
  cout << "Welcome to the path reverser program.\n";
  while (another == 'y' || another == 'Y') {
    cout << "Enter a path as a series of steps (NSEW), press enter when done ";
    getline(cin, path);
    if (validInput(path)) {
      mazepath = path;
      cout << "The path is: " << mazepath << endl;
      cout << "The reversed path is:" << mazepath.directionsOut() << endl;
      cout << "Another? (Y/N) ";
      cin >> another;
    } else {
      cout << "Path is not valid (must only contain (NSEW))\n";
    }
  }
}
