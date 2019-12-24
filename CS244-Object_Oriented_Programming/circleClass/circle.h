/*
//Name: Elvis Rodriguez
//Date: 3-6-18
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

#define PI 3.14159265359

class Circle {
  private:
    double center_x;
    double center_y;
    double diameter;
    double radius;
  public:
    Circle();
    Circle(double);
    Circle(double, double);
    void changeCenter(double, double);
    double getCenter_x() const;
    double getCenter_y() const;
    void setRadius(double);
    void setDiameter();
    double getRadius() const;
    double getDiameter() const;
    double area() const;
    double circumference() const;
};

#endif //CIRCLE_H
