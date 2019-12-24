/*
//Name: Elvis Rodriguez
//Date: 2-27-18
*/

#include "point.h"

Point::Point() {
  x = 0;
  y = 0;
}

Point::Point(double x = 0, double y = 0) {
  this->x = x;
  this->y = y;
}

void Point::shift(double dx, double dy) {
  x += dx;
  y += dy;
}

double Point::get_x() const {
  return x;
}

double Point::get_y() const {
  return y;
}

void Point::absResetx(int value) {
  x = value;
}

void Point::absResety(int value) {
  y = value;
}

void Point::xIntoy() {
  x = y;
}

void Point::yIntox() {
  y = x;
}
