#include <iostream>
#include <cassert>
#include <unordered_set>

using namespace std;

int sum2(int A1[], int A2[], int n1, int n2, int x) {
  int count = 0;
  int diff;
  unordered_set<int> A2_set;
  for (int i = 0; i < n2; i++) {
    A2_set.insert(A2[i]);
  }
  for (int i = 0; i < n1; i++) {
    diff = x - A1[i];
    unordered_set<int>::const_iterator found = A2_set.find(diff);
    if (found != A2_set.end()) {
      count++;
    }
  }
  return count;
}

int main() {
  int A1[6] = {4,5,2,7,8,10};
  int A2[6] = {1,9,-4,12,-7,-6};

  int result = sum2(A1, A2, 6, 6, 6);
  assert(result == 2);

  result = sum2(A1, A2, 6, 6, 0);
  assert(result == 2);

  result = sum2(A1, A2, 6, 6, 7);
  assert(result == 0);

  int B1[13] = {5, 2, 7, -8, 10, -20, 13, 64, 0, -36, -10, -4, -44};
  int B2[54] = {1, 2, 3, 5, 6, 7, 8, 10, 12, 13, 14, 15, 16, 17, 19, 20, 21,
              22, 23, 25, 26, 27, 28, 30, 31, 33, 34, 35, 36, 37, 41, 41, 43,
              44, 47, 48, 49, 50, 51, 52, 53, 54, 56, 57, 58, 63, 64, 65, 67,
              68, 69, 70, 75, 80};

  result = sum2(B1, B2, 13, 54, 14);
  assert(result == 8);
}
