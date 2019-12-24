#include "clock.h"

int main() {
  Clock face(12,30);

  assert(face.getHour() == 12);
  assert(face.getMinute() == 30);

  face.setHour(2400);
  face.setMinute(600);

  assert(face.getHour() == 0);
  assert(face.getMinute() == 0);

  face.currentTime();

  return 0;
}
