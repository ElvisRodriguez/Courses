#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#define pi 3.14159265359

class Circle: public Shape {
  private:
    double radius;
  public:
    Circle();
    Circle(double);
    void setRadius(double);
    double getRadius() const;
    double diameter() const;
    double circumference() const;
    double area();
    ~Circle();
};

#endif //CIRCLE_H
