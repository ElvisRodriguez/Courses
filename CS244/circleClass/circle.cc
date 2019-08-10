/*
//Name: Elvis Rodriguez
//Date: 3-6-18
*/

#include "circle.h"

Circle::Circle() {
  center_x = 0;
  center_y = 0;
}

Circle::Circle(double xy) {
  center_x = xy;
  center_y = xy;
}

Circle::Circle(double x, double y) {
  center_x = x;
  center_y = y;
}

void Circle::changeCenter(double x, double y) {
  center_x = x;
  center_y = y;
}

double Circle::getCenter_x() const {
  return center_x;
}

double Circle::getCenter_y() const {
  return center_y;
}

void Circle::setRadius(double r = 1) {
  radius = r;
}

void Circle::setDiameter() {
  diameter = radius * 2;
}

double Circle::getRadius() const {
  return radius;
}

double Circle::getDiameter() const {
  return diameter;
}

double Circle::area() const {
  double result;
  result = PI * (pow(radius, 2));
  return result;
}

double Circle::circumference() const {
  double result;
  result = 2 * PI * radius;
  return result;
}
