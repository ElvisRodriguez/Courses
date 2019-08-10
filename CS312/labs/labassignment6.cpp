#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isPalindrome(string str) {
  if (str.length() <= 1) {
    return true;
  } else if (str[0] == str[str.length() - 1]) {
      str.erase(0,1);
      str.erase(str.length() - 1, 1);
      return isPalindrome(str);
    } else {
        return false;
    }
}

int main() {
  string samples[5] = {"racecar", "z", "1234321", "toot", "hello"};
  assert(isPalindrome(samples[0]));
  assert(isPalindrome(samples[1]));
  assert(isPalindrome(samples[2]));
  assert(isPalindrome(samples[3]));
  assert(!isPalindrome(samples[4]));

  return 0;
}
