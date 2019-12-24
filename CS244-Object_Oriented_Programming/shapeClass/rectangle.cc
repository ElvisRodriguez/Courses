#include "rectangle.h"

Rectangle::Rectangle() {
  cout << "Rectangle object created\n";
  length = 2;
  width = 2;
}

Rectangle::Rectangle(double length, double width) {
  cout << "Rectangle object created\n";
  this->length = length;
  this->width = width;
}

void Rectangle::setLength(double length = 1) {
  this->length = length;
}

void Rectangle::setWidth(double width = 1) {
  this->width = width;
}

double Rectangle::getLength() const {
  return length;
}

double Rectangle::getWidth() const {
  return width;
}

bool Rectangle::isSquare() const {
  if (length == width) {
    return true;
  }
  return false;
}

double Rectangle::area() {
  if (isSquare()) {
    return length * length;
  }
  return length * width;
}

double Rectangle::perimeter() {
  if (isSquare()) {
    return 4 * length;
  }
  return (2 * length) + (2 * width);
}

Rectangle::~Rectangle() {
  cout << "Rectangle object destroyed\n";
}
