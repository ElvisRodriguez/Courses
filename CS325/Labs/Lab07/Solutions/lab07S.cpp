#include <iostream>
#include <string>

/******************************************************************************
Q: Given that the addresses of the variables X, Y and Z are 23, 63, and 81
respectively, write a NWI program that performs the expression Z = (X % Y) * X
A:
	01 72350 or 71750
	02 45063 or 4503F
	03 65000 or 65000
	04 35023 or 3503F
	05 75081 or 75051
	06 00000 or 00000
******************************************************************************/

//define function below here
std::string ToPostfix(std::string exp)
{
	std::string v = "", s = " ";
	int n = exp.length();

	for(int i = 0;i < n;i += 1)
	{
		if(exp[i] != ' ')
		{
			v += exp[i];
		}
	}

	if(v.length() != 3)
	{
		v = "";
	}
	else if(!(v[1] == '+' || v[1] == '-' || v[1] == '*' || v[1] == '/' || v[1] == '%'))
	{
		v = "";
	}
	else if(!(v[0] >= 'a' && v[0] <= 'z') || !(v[2] >= 'a' && v[2] <= 'z'))
	{
		v = "";
	}
	else 
	{
		v = v[0] + s + v[2] + s + v[1];
	}
	return v;
}

//define function above here

int main()
{
	std::string exp;

	std::cout << "Enter expression: ";
	std::getline(std::cin,exp);
	std::cout << "ToPostfix(\"" + exp + "\") = " << ToPostfix(exp) << "\n";

	return 0;
}
