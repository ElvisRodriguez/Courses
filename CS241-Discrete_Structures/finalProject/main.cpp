#include "goldbach.h"

int main() {
  int primes[SIZE];
  allPrimes(primes);
  writeConjectures(primes);

  return 0;
}
