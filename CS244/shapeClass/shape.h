#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
  protected:
    double x;
    double y;
  public:
    Shape();
    void setValues(double, double);
    double getx() const;
    double gety() const;
    virtual double area() {return 0;};
    ~Shape();
};

#endif //SHAPE_H
