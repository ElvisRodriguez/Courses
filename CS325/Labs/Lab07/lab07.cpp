#include <iostream>
#include <string>

using namespace std;

#define EQUATION_SIZE 5

bool IsOperator(char _operator) {
	// Checks if _operator is an accepted operator
	char operators[5] = {'+', '-', '/', '*', '%'};
	for (int i = 0; i < 5; i++) {
		if (_operator == operators[i]) {
			return true;
		}
	}
	return false;
}

string ToPostFix(string exp) {
	/*
		Converts an infix expression, exp, into a postfix expression, postfix.
		exp must be a string of size 5 in the format:
			"<operand> <operator> <operand>""
		Returns:
			postfix expression if exp is valid, empty string otherwise.
	*/
	if (exp.length() != EQUATION_SIZE) {
		return "";
	}
	if (exp[1] != ' ' || exp[3] != ' ') {
		return "";
	}
	if (!(IsOperator(exp[2]))) {
		return "";
	}
	char postfixArray[EQUATION_SIZE] = {' ',' ',' ',' ',' '};
	for (int i = 0; i < EQUATION_SIZE; i++) {
		postfixArray[i] = exp[i];
	}
	postfixArray[2] = exp[4];
	postfixArray[4] = exp[2];
	string postfix = "";
	for (int i = 0; i < EQUATION_SIZE; i++) {
		postfix += postfixArray[i];
	}
	return postfix;
}

int main()
{
	string exp = "a + b";
	string bad_exp = "a * b + c";
	cout << exp << ": to postfix: " << ToPostFix(exp) << endl;
	cout << bad_exp << ": to postfix: " << ToPostFix(bad_exp) << endl;
	return 0;
}
