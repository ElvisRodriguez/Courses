/*
//Name: Elvis Rodriguez
//Creation: 11/17/2017
//Version: 6.R
//Description: opens a file for reading, creates a new file, and copies the
               content of the original file to the newly created file.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "CP_command.h"
/*
//Name: main()
//Parameter(s): None
//Returns: int
//Label   Task                                Goto
//01      (start)                             02
//02      [init filename: string]             03
//03      /print("Enter filename: ")/         04
//04      /filename = str(input())/           05
//05      [Copy(filename)]                    06
//06      (exit: 0)
*/
int main() {
  string filename;

  cout << "Enter filename: ";
  cin >> filename;

  Copy(filename);
}
