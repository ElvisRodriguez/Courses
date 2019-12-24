#include "baseball.h"

int main() {
  srand(time(NULL));

  BaseballPlayer x("Elvis");

  assert(x.getHits() == 0);
  assert(x.getAtBats() == 0);
  assert(x.getOuts() == 0);

  x.getName();

  x.playBall(100);

  cout << "Final average: " << x.getBattingAverage() << endl;

  return 0;
}
