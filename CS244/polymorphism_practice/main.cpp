#include "rational.h"

int main() {
  Rational *rp;
  int a, b;
  cout << "Enter a and b:\n";
  cin >> a >> b;
  rp = new Rational(a,b);
  rp->Display();
  delete rp;
  rp = NULL;
}
