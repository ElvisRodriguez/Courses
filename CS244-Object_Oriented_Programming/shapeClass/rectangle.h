#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape {
  private:
    double length;
    double width;
  public:
    Rectangle();
    Rectangle(double, double);
    void setLength(double);
    void setWidth(double);
    double getLength() const;
    double getWidth() const;
    bool isSquare() const;
    double area();
    double perimeter();
    ~Rectangle();
};

#endif //RECTANGLE_H
