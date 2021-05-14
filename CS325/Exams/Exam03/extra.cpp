#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

std::string ToString(bool a[],int n)
{
	std::string out = "[";

	for(int i = 0;i < n;i += 1)
	{
		out += (a[i])?("1"):("0");

		if(i + 1 < n)
		{
			out += ",";
		}
	}
	out += "]";
	return out;
}

void generateArray(bool a[],int n)
{
	for(int i = 0;i < n;i += 1)
	{
		a[i] = rand() % 2 == 0;
	}
}

//define below here

//define above here

int main()
{
	srand(time(NULL));
	bool *a, *b, *r;
	int n;

	std::cout << "Enter a length: ";
	std::cin >> n;

	if(n <= 0)
	{
		n = 4;
	}

	a = new bool[n];
	b = new bool[n];
	r = new bool[n];

	generateArray(a,n);
	generateArray(b,n);
	generateArray(r,n); //replace with addition caller

	std::cout << "  a = " << ToString(a,n) << "\n";
	std::cout << "+ b = " << ToString(b,n) << "\n";
	std::cout << std::setfill('-') << std::setw(8 + 2 * n) << "-" << "\n";
	std::cout << "  r = " << ToString(r,n) << "\n";

	delete[] a;
	delete[] b;
	delete[] r;
	return 0;
}
