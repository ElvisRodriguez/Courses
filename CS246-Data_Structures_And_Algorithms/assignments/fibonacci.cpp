/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Directive: Write a function that returns the nth value of the Fibonacci
             sequence where n is a value given by a user
*/
#include <iostream>
using namespace std;

int fibonacciSequence(int n) {
  if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    return fibonacciSequence(n-1) + fibonacciSequence(n-2);
  }
}

int main() {
  int num;
  cout << "Enter a number\n";
  cin >> num;
  cout << "The " << num << "th value in the Fibonacci sequence is ";
  cout << fibonacciSequence(num) << endl;
}
