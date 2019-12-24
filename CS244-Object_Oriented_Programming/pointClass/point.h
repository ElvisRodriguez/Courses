/*
//Name: Elvis Rodriguez
//Date: 2-27-18
*/
#ifndef POINT_H
#define POINT_H

class Point {
  private:
    double x, y;
  public:
    Point();
    Point(double, double);
    void shift(double, double);
    double get_x() const;
    double get_y() const;
    void absResetx(int);
    void absResety(int);
    void xIntoy();
    void yIntox();
};

#endif //POINT_H
