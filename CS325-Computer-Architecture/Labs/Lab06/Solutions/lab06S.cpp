#include <iostream>
#include <string>

/*************************************************************************
Q: Given that the addresses of the variables X, Y and Z are 16, 48, 54
respectively, write an IAS program that performs the expression 
Z = X + Y * Z
A:
	090480B054
	0A00005016
	2105400000
*************************************************************************/

/**********************************
* define function below here
**********************************/
void Push(std::string& stack,char item)
{
	if(stack.length() < 100)
	{
		stack = item + stack;
	}
}

bool IsEmpty(const std::string& stack)
{
	return stack.length() == 0;
}

char Top(const std::string& stack)
{
	if(stack.length() != 0)
	{
		return stack[0];
	}
	throw "Empty Stack";
}

/*********************************
* define function above here
*********************************/

int main()
{
	return 0;
}
