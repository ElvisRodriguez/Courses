//Name: Elvis Rodriguez
//Question 5: Convert an infix expression into a prefix expression

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isAnOperator(char c) {
  return (!isalpha(c) && !isdigit(c));
}

int OrderPrecedence(char c) {
  if (c == '-' || c == '+')
      return 1;
  else if (c == '*' || c == '/')
      return 2;
  else if (c == '^')
      return 3;
  return 0;
}

string infixToPostfix(string infix) {
    infix = '(' + infix + ')';
    int n = infix.length();
    stack<char> chars;
    string output;
    for (int i = 0; i < n; i++) {
      if (isalpha(infix[i]) || isdigit(infix[i])) {
        output += infix[i];
      } else if (infix[i] == '(') {
          chars.push('(');
      } else if (infix[i] == ')') {
          while (chars.top() != '(') {
            output += chars.top();
            chars.pop();
          }
          chars.pop();
        } else {
            if (isAnOperator(chars.top())) {
              while (OrderPrecedence(infix[i]) <= OrderPrecedence(chars.top())) {
                output += chars.top();
                chars.pop();
              }
              chars.push(infix[i]);
            }
          }
    }
  return output;
}

string infixToPrefix(string infix) {
  int n = infix.length();
  reverse(infix.begin(), infix.end());
  for (int i = 0; i < n; i++) {
    if (infix[i] == '(') {
      infix[i] = ')';
      i++;
    } else if (infix[i] == ')') {
        infix[i] = '(';
        i++;
      }
  }
  string prefix = infixToPostfix(infix);
  reverse(prefix.begin(), prefix.end());
  return prefix;
}

int main() {
  cout << infixToPrefix("(a+b)") << endl;
  return 0;
}
