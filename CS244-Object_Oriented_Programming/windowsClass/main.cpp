#include "windows.h"

int main() {
  
  cout << "Default window size:\n";
  Windows test;

  cout << "\n\tMinimized Window\n";
  test.minimize();

  cout << "\n\tMaximized Window\n";
  test.maximize();

  cout << "\n\tRestored Window (Same size as default)\n";
  test.restore();

  cout << "\n\tWindow moved 5 units to the left\n";
  test.move(5);

  return 0;
}
