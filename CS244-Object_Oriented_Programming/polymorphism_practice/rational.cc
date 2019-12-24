#include "rational.h"

Rational::Rational(int n, int d) {
  numerator = n;
  denominator = d;
}

void Rational::Display()  {
  cout << numerator << "/" << denominator << endl;
}
