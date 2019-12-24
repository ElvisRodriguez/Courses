/*
//Name: Elvis Rodriguez
//Creation: 09/27/2017
//Version: 2.R
//Description: Prompts the user to enter two (2) vectors in polar coordinates with the angle in degrees
               separately. Prints the vectors, their sum and differences in both polar and rectangular coordinates.
*******************************************************************************************************************/
#ifndef VECTORS_H
#define VECTORS_H

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#define PI 3.14159265

using namespace std;
/*
//Name: toDegrees()
//Parameter(s): double rad
//Return: double
//Label    Task                                 Goto
//01       (start: rad)                         02
//02       [rad * (180/PI) --> result]          03
//03       (exit: result)
*/
double toDegrees(double rad) {
  double result = rad * (180 / PI);
  return result;
}
/*
//Name: toRadian()
//Parameter(s): double deg
//Return: double
//Label     Task                                Goto
//01        (start: deg)                        02
//02        [deg * (PI/180) --> result]         03
//03        (exit: result)
*/
double toRadian(double deg) {
  double result = deg * (PI / 180);
  return result;
}
/*
//Name: toRectangular()
//Parameter(s): double magnitude, double angle, double& x, double&y
//Return: none
//Label     Task                                Goto
//01        (start: magnitude, angle, x, y)     02
//02        [toRadian(angle) --> angle]         03
//03        [magnitude * cos(angle) --> x]      04
//04        [magnitude * sin(angle) --> y]      05
//05        (exit)
*/
void toRectangular(double magnitude, double angle, double& x, double&y) {
  angle = toRadian(angle);
  x = ( magnitude * ( cos (angle) ) );
  y = ( magnitude * ( sin (angle) ) );
}
/*
//Name: toPolar()
//Parameter(s): double x, double y, double& magnitude, double& angle
//Return: none
//Label       Task                                  Goto
//01          (start: x, y, magnitude, angle)       02
//02          [sqrt(x^2 + y^2) --> magnitude]       03
//03          [toDegrees(atan2(y,x)) --> angle]     04
//04          (exit)
*/
void toPolar(double x, double y, double& magnitude, double& angle){
  magnitude = ( sqrt ( (x * x) + (y * y) ) );
  angle = toDegrees( atan2 (y, x) );
}
/*
//Name: add()
//Parameter(s): double mag1, double ang1, double mag2, double ang2, double& mag3, double& ang3
//Return: double
//Label       Task                                            Goto
//01          (start: mag1, ang1, mag2, ang2, mag3, ang3)     02
//02          [double x1, x2, y1, y2]                         03
//03          [toRectangular(mag1, ang1, x1, y1)]             04
//04          [toRectangular(mag2, ang2, x2, y2)]             05
//05          [x1 + x2 --> mag3]                              06
//06          [y1 + y2 --> ang3]                              07
//07          [toPolar(mag3, ang3, mag3, ang3)]               08
//08          (exit: 0.0)
*/
double add(double mag1, double ang1, double mag2, double ang2, double& mag3, double& ang3) {
  double x1, x2, y1, y2;
  toRectangular(mag1, ang1, x1, y1);
  toRectangular(mag2, ang2, x2, y2);
  mag3 = x1 + x2;
  ang3 = y1 + y2;
  toPolar(mag3, ang3, mag3, ang3);
  return 0.0;
}
/*
//Name: subtract()
//Parameter(s): double mag1, double ang1, double mag2, double ang2, double& mag3, double& ang3
//Return: double
//Label       Task                                            Goto
//01          (start: mag1, ang1, mag2, ang2, mag3, ang3)     02
//02          [double x1, x2, y1, y2]                         03
//03          [toRectangular(mag1, ang1, x1, y1)]             04
//04          [toRectangular(mag2, ang2, x2, y2)]             05
//05          [x1 + (-1 * x2) --> mag3]                       06
//06          [y1 + (-1 * y2) --> ang3]                       07
//07          [toPolar(mag3, ang3, mag3, ang3)]               08
//08          (exit: 0.0)
*/
double subtract(double mag1, double ang1, double mag2, double ang2, double& mag3, double& ang3) {
  double x1, x2, y1, y2;
  toRectangular(mag1, ang1, x1, y1);
  toRectangular(mag2, ang2, x2, y2);
  mag3 = x1 + (-1 * x2);
  ang3 = y1 + (-1 * y2);
  toPolar(mag3, ang3, mag3, ang3);

  return 0.0;
}

#endif //VECTORS_H
