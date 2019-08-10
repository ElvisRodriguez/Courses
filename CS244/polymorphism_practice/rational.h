#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational {
  private:
    int numerator, denominator;
  public:
    Rational(int, int);
    void Display();
};

#endif //RATIONAL_H
