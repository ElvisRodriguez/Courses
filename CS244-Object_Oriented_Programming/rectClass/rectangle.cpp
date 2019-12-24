/*
//Name: Elvis Rodriguez
//Date: 3-1-18
*/

#include <iostream>
using namespace std;

#include "rectangle.h"

int main() {
  Rectangle rect1;
  Rectangle rect2(3,3);

  cout << "Rectangle's default values\n";
  cout << "Rectangle 1: (" << rect1.getLength();
  cout << " , " << rect1.getWidth() << ")\n";

  cout << "Rectangle 2: (" << rect2.getLength();
  cout << " , " << rect2.getWidth() << ")\n";

  cout << "Changing rectangle values\n";

  rect1.setWidth(2.5);
  rect1.setLength(3.7);

  rect2.setWidth(5);
  rect2.setLength(5);

  cout << "New Rectangle values\n";

  cout << "Rectangle 1: (" << rect1.getLength();
  cout << " , " << rect1.getWidth() << ")\n";
  cout << "Area " << rect1.getArea() << endl;

  cout << "Rectangle 2: (" << rect2.getLength();
  cout << " , " << rect2.getWidth() << ")\n";
  cout << "Area " << rect2.getArea() << endl;

  return 0;
}
