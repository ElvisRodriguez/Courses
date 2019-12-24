/*
//Name: Elvis Rodriguez
//Creation: 09/27/2017
//Version: 2.R
//Description: Prompts the user to enter two (2) vectors in polar coordinates with the angle in degrees
               separately. Prints the vectors, their sum and differences in both polar and rectangular coordinates.
*******************************************************************************************************************/
#include "vectors.h"
/*
//Name: Main()
//Paramter(s): none
//Return: int
//Label       Task                                                          Goto
//01          (start)                                                       02
//02          [double x, y, mag1, mag2, mag3, ang1, ang2, ang3]             03
//03          /print("Enter the first vector:")/                            04
//04          /input --> mag1, ang1/                                        05
//05          /print("Enter the second vector:")                            06
//06          /input --> mag2, ang2/                                        07
//07          /print("\n")/                                                 08
//08          /print(fixed, setprecision(1))/                               09
//09          /print("v1:\n")/                                              10
//10          [toRectangular(mag1, ang1, x, y)]                             11
//11          [toPolar(x, y, mag1, ang1)]                                   12
//12          /print("Polar Coordinates: (", mag1, ",", ang1, ")\n")/       13
//13          /print("Rectangular Coordinates: (", x, ",", y, ")\n")/       14
//14          /print("v2:\n")/                                              15
//15          [toRectangular(mag2, ang2, x, y)]                             16
//16          [toPolar(x, y, mag2, ang2)]                                   17
//17          /print("Polar Coordinates: (",mag2,",",ang2,")\n")/           18
//18          /print("Rectangular Coordinates: (",x,",",y,")\n"/            19
//19          /print("v1 + v2:\n")/                                         20
//20          [add(mag1, ang1, mag2, ang2, mag3, ang3)]                     21
//21          /print("Polar Coordinates: (",mag3,",",ang3,")\n")/           22
//22          [toRectangular(mag3, ang3, x, y)]                             23
//23          /print("Rectangular Coordinates: (",x,",",y,")\n")/           24
//24          /print("v1 - v2:\n")/                                         25
//25          [subtract(mag1, ang1, mag2, ang2, mag3, ang3)]                26
//26          /print("Polar Coordinates: (",mag3,",",ang3,")\n")/           27
//27          [toRectangular(mag3, ang3, x, y)]                             28
//28          /print("Rectangular Coordinates: (",x,",",y,")\n")/           29
//29          /print("v2 - v1:\n")/                                         30
//30          [subtract(mag2, ang2, mag1, ang1, mag3, ang3)]                31
//31          /print("Polar Coordinates: (",mag3,",",ang3,")\n")/           32
//32          [toRectangular(mag3, ang3, x, y)]                             33
//33          print("Rectangular Coordinates: (",x,",",y,")\n")/            34
//34          (exit: 0)
*/
int main() {
  double x, y, mag1, mag2, mag3, ang1, ang2, ang3;

  cout << "Enter the first vector:";
  cin >> mag1 >> ang1;

  cout << "Enter the second vector:";
  cin >> mag2 >> ang2;

  cout << endl;

  cout << fixed << setprecision(1);

  cout << "v1:\n";
  toRectangular(mag1, ang1, x, y);
  toPolar(x, y, mag1, ang1);
  cout << "Polar Coordinates: (" << mag1 << "," << ang1 << ")\n";
  cout << "Rectangular Coordinates: (" << x << "," << y << ")\n";


  cout << "v2:\n";
  toRectangular(mag2, ang2, x, y);
  toPolar(x, y, mag2, ang2);
  cout << "Polar Coordinates: (" << mag2 << "," << ang2 << ")\n";
  cout << "Rectangular Coordinates: (" << x << "," << y << ")\n";


  cout << "v1 + v2:\n";
  add(mag1, ang1, mag2, ang2, mag3, ang3);
  cout << "Polar Coordinates: (" << mag3 << "," << ang3 << ")\n";
  toRectangular(mag3, ang3, x, y);
  cout << "Rectangular Coordinates: (" << x << "," << y << ")\n";


  cout << "v1 - v2:\n";
  subtract(mag1, ang1, mag2, ang2, mag3, ang3);
  cout << "Polar Coordinates: (" << mag3 << "," << ang3 << ")\n";
  toRectangular(mag3, ang3, x, y);
  cout << "Rectangular Coordinates: (" << x << "," << y << ")\n";


  cout << "v2 - v1:\n";
  subtract(mag2, ang2, mag1, ang1, mag3, ang3);
  cout << "Polar Coordinates: (" << mag3 << "," << ang3 << ")\n";
  toRectangular(mag3, ang3, x, y);
  cout << "Rectangular Coordinates: (" << x << "," << y << ")\n";

  return 0;
}
