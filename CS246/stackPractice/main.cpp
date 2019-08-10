#include "hexConver.h"

int main() {
  int num;

  cout << "Enter Number: ";
  cin >> num;

  cout << num << " converted to hex is ";
  cout << numToHexadecimal(num) << endl;

  return 0;
}
