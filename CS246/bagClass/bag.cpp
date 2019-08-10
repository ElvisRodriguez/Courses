#include "bag.h"

int main() {
  int x = 25;
  int randNum;
  Bag ofBeans(x);

  assert(ofBeans.size() == 0);

  srand(time(0));

  for (int i = 1; i <= x; i++) {
    randNum = rand() % x + 1;
    ofBeans.insert(randNum);
  }

  assert(ofBeans.size() == x);

  for (int i = 0; i < x; i++) {
    cout << ofBeans.occurences(i) << " ";
  }
  cout << endl;

  ofBeans.destroy();

  return 0;
}
