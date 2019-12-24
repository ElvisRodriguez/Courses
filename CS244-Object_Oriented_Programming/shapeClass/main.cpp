#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

#define NDEBUG
#include <cassert>

#define SIZE 3

int main() {
  Shape *shapes[SIZE];
  Circle circ;
  Triangle tri;
  Rectangle rect;

  shapes[0] = &circ;
  shapes[1] = &tri;
  shapes[2] = &rect;
  for (int i = 0; i < SIZE; i++) {
    cout << "Area of object " << i << endl;
    cout << shapes[i]->area() << endl;
  }

  return 0;
}
