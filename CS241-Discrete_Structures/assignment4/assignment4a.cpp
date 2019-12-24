#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int GCD(int m, int n) {
  if ((m % n) == 0) {
    return n;
  } else if ((m % n) != 0) {
    return GCD(n, (m % n));
  }
}

int Phi(int n) {
  if (n < 1) {
    return 0;
  } else {
    int count = 0;
    for (int i = 1; i < n; i++) {
      if (GCD(n,i) == 1) {
        count++;
      }
    }
    if (n == 1) {
      count++;
    }
    return count;
  }
}

int main() {
  ofstream out;
  out.open("data.txt");
  for (int i = 1; i <= 100; i++) {
    out << setw(3) << setfill('0');
    out << "phi(" << i << ") = " << Phi(i) << "\n";
  }
  out.close();
  return 0;
}
