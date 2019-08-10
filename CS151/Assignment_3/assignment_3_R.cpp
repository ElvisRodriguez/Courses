/*
//Name: Elvis Rodriguez
//Creation: 10/11/2017
//Version: 3.R
//Description: Prompts the user for five (5) inputs of type float and returns
               the maximum, minimum, median, first quartile, and third
               quartile of those five (5) numbers.
*/
#include <iostream>
#include <iomanip>
using namespace std;

#include "fivePointStats.h"


/*
//Name: main()
//Parameter(s): none
//Return: int
//Label       Task                                                              Goto
//01          (start)                                                           02
//02          [float x, y, z, w, v]                                             03
//03          /print("Enter 5 numbers:")/                                       04
//04          /input --> x, y, z, w, v/                                         05
//05          /print(fixed, setPrecision(1))/                                   06
//06          /print("The maximum is", maximum(x,y,z,w,v), "\n")/               07
//07          /print("The third quartile is", thirdQuartile(x,y,z,w,v), "\n")/  08
//08          /print("The median is", median(x,y,z,w,v), "\n")/                 09
//09          /print("The first quartile is", firstQuartile(x,y,z,w,v), "\n")/  10
//10          /print("The minimum is", minimum(x,y,z,w,v), "\n")/               11
//11          (exit: 0)
*/
int main() {
  float x, y, z, w, v;

  cout << "Enter 5 numbers:";
  cin >> x >> y >> z >> w >> v;

  cout << fixed << setprecision(1);

  cout << "The maximum is " << maximum(x, y, z, w, v) << endl;
  cout << "The third quartile is " << thirdQuartile(x, y, z, w, v) << endl;
  cout << "The median is " << median(x, y, z, w, v) << endl;
  cout << "The first quartile is " << firstQuartile(x, y, z, w, v) << endl;
  cout << "The minimum is " << minimum(x, y, z, w, v) << endl;

  return 0;
}
