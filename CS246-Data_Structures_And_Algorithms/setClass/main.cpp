#include "sets.h"

int main() {
  Set x;
  Set y;

  int arr[5] = {2,7,11,18,23};
  int testArray[5] = {1,2,3,4,4};

  assert(x.getSize() == 5);
  assert(x.insertData(arr));

  cout << "Set x: " << x.getData();
  cout << endl;

  assert(!(y.insertData(testArray)));

  cout << "Set y: " << y.getData();
  cout << endl;

  cout << "x union y:\n";
  cout << x.dataUnion(y);
  cout << endl;

  cout << "x intersect y:\n";
  cout << x.dataIntersection(y);
  cout << endl;

  cout << "x difference y:\n";
  cout << x.dataDifference(y);
  cout << endl;

  cout << "x times y:\n";
  cout << x.dataCartesianProduct(y);
  cout << endl;

  cout << "y union x:\n";
  cout << y.dataUnion(x);
  cout << endl;

  cout << "y intersect x:\n";
  cout << y.dataIntersection(x);
  cout << endl;

  cout << "y difference x:\n";
  cout << y.dataDifference(x);
  cout << endl;

  cout << "y times x:\n";
  cout << y.dataCartesianProduct(x);
  cout << endl;

  x.garbageCollection();
  y.garbageCollection();

  return 0;
}
