#include "circle.h"

Circle::Circle() {
  cout << "Circle object created\n";
  radius = 1;
}

Circle::Circle(double radius) {
  cout << "Circle object created\n";
  this->radius = radius;
}

void Circle::setRadius(double radius = 1) {
  this->radius = radius;
}

double Circle::getRadius() const {
  return radius;
}

double Circle::diameter() const {
  return radius * 2;
}

double Circle::circumference() const {
  return 2 * pi * radius;
}

double Circle::area() {
  return pi * pow(radius,2);
}

Circle::~Circle() {
  cout << "Circle object destroyed\n";
}
