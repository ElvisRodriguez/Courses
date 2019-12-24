/*
//Name: Elvis Rodriguez
//Date: 3-1-18
*/

#include "rectangle.h"

Rectangle::Rectangle() {
  length = 0;
  width = 0;
}

Rectangle::Rectangle(double initLength, double initWidth) {
  if (initLength >= 0 && initWidth >= 0) {
    length = initLength;
    width = initWidth;
  } else {
    length = 0;
    width = 0;
  }
}

void Rectangle::setWidth(double initWidth = 0) {
  if (initWidth >= 0) {
    width = initWidth;
  } else {
    width = 0;
  }
}

void Rectangle::setLength(double initLength = 0) {
  if (initLength >= 0) {
    length = initLength;
  } else {
    length = 0;
  }
}

double Rectangle::getWidth() const {
  return width;
}

double Rectangle::getLength() const {
  return length;
}

double Rectangle::getArea() const {
  return (length * width);
}
