#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int big_num;
#define MAX_BOTTOM_UP_SIZE 134000000
#define MAX_TOP_DOWN_SIZE 100000000/573

big_num fib(big_num n) {
  // Runtime: O(2^n) -> inputs greater than 45 will start taking minutes,
  //                    then hours, years, etc very very quickly
  if (n < 2) return n;
  else return fib(n-1) + fib(n-2);
}

big_num fib_bottom_up(big_num n) {
  // Runtime: O(n)
  if (n < 2) return n;
  vector<big_num> memo;
  memo.push_back(0);
  memo.push_back(1);
  for (big_num j = 2; j <= n; j++) {
    memo.push_back(memo[j-1]+memo[j-2]);
  }
  return memo[n];
}

vector<big_num> saveF(MAX_TOP_DOWN_SIZE);

big_num fib_top_down(big_num n) {
  // Runtime: O(n) -> recursion stack will overflow with large inputs.
  if (saveF[n] > 0) return saveF[n];
  if (n < 2) return n;
  saveF[n] = fib_top_down(n - 1) + fib_top_down(n - 2);
  return saveF[n];
}

int main() {
  big_num A = 45;
  big_num B = MAX_BOTTOM_UP_SIZE;
  big_num C = MAX_TOP_DOWN_SIZE;
  //cout << "Slow Recurisive Fibonacci: "<< fib(A) << endl; //8 seconds to compute
  cout << "Bottom Up Fibonacci: " << fib_bottom_up(B) << endl; //4 seconds to compute
  cout << "Top Down Fibonacci: " << fib_top_down(C) << endl;
  //<1 second to compute, recursion stack overflows with any larger input
  return 0;
}
