#include "shape.h"

Shape::Shape() {
  cout << "Shape object created\n";
  x = 0;
  y = 0;
}

void Shape::setValues(double x = 0, double y = 0) {
  this->x = x;
  this->y = y;
}
double Shape::getx() const {
  return x;
}

double Shape::gety() const {
  return y;
}

Shape::~Shape() {
  cout << "Shape object destroyed\n";
}
