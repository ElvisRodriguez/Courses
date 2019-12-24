/*
//Name: Elvis Rodriguez
//Date: 3-6-18
*/

#include "circle.h"

//#define NDEBUG

int main() {
  Circle c;

  assert(c.getCenter_x() == 0);
  assert(c.getCenter_y() == 0);

  c.changeCenter(2.5, 3.6);

  assert(c.getCenter_x() == 2.5);
  assert(c.getCenter_y() == 3.6);

  c.setRadius(4);
  assert(c.getRadius() == 4);

  c.setDiameter();
  assert(c.getDiameter() == 8);

  assert(c.area() == (PI * ( pow( c.getRadius(), 2 )) ) );

  assert(c.circumference() == 2 * PI * c.getRadius() );

  return 0;
}
