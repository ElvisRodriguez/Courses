/*
//Name: Elvis Rodriguez
//Date: 3-1-18
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
  private:
    double length;
    double width;
  public:
    Rectangle();
    Rectangle(double, double);
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

#endif //RECTANGLE_H
