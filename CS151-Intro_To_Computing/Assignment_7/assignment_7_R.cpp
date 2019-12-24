/*
//Name: Elvis Rodriguez
//Creation: 11/27/2017
//Version: 7.R
//Description: Builds an array of random number between two user-given parameters,
               displays that array, then sorts the same array and displays that.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "random.h"

/*
//Name: main()
//Parameter(s): None
//Returns: int
//Label   Task                                                            Goto
//01      (start)                                                         02
//02      [init int_array with size 10]                                   03
//03      [init min, max as int]                                          04
//04      /print("Enter two distinct numbers:")/                          05
//05      /input --> min, max/                                            06
//06      [RandomNumbers(int_array, 10, min, max)]                        07
//07      [PrintArray(int_array, 10)]                                     08
//08      [Sort(int_array, 10)]                                           09
//09      [PrintArray(int_array, 10)]                                     10
//10      (exit: 0)
*/
int main() {
  int int_array[10];
  int min, max;

  cout << "Enter two distinct numbers:";
  cin >> min >> max;

  RandomNumbers(int_array, 10, min, max);
  PrintArray(int_array, 10);

  Sort(int_array, 10);
  PrintArray(int_array, 10);
  return 0;
}
