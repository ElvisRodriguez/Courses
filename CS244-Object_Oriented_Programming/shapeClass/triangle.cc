#include "triangle.h"

Triangle::Triangle() {
  sides[0] = 2;
  sides[1] = 3;
  sides[2] = 4;
  cout << "Triangle object created\n";
}

Triangle::Triangle(double A, double B, double C) {
  sides[0] = A;
  sides[1] = B;
  sides[2] = C;
  cout << "Triangle object created\n";
}

double Triangle::base() const {
  return sides[0];
}

double Triangle::height() const{
  return sqrt(pow(sides[1],2) + pow(base()/2,2));
}

double Triangle::area() {
  return (base()/2) * height();
}

double Triangle::perimeter() const {
  return sides[0] + sides[1] + sides[2];
}

Triangle::~Triangle() {
  cout << "Triangle object destroyed\n";
}
