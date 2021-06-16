#include <iostream>
#include <string>

/**********************************
* define function below here
**********************************/

bool IsEmpty(const std::string& stack) {
	return stack.length() == 0;
}

void Push(std::string& stack, char item) {
	if (stack.length() < 100) {
		stack = item + stack;
	}
}

char Top(const std::string& stack) {
	if (!IsEmpty(stack)) {
		return stack[0];
	} else {
		throw "Empty Stack";
	}
}

/*********************************
* define function above here
*********************************/

int main()
{
	return 0;
}
