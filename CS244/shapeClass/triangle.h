#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle: public Shape {
  private:
    double sides[3];
  public:
    Triangle();
    Triangle(double, double, double);
    double base() const;
    double height() const;
    double area();
    double perimeter() const;
    ~Triangle();
};

#endif //TRIANGLE_H
