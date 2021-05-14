#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string ToString(bool a[])
{
	std::string r = "";

	for(int i = 0;i < 32;i += 1)
	{
		r += (a[i])?("1"):("0");
	}
	return r;
}

void PopulateWord(bool a[])
{
	for(int i = 0;i < 32;i += 1)
	{
		a[i] = (rand() % 2 == 0);
	}
}

void GE(bool a[],bool b[],bool r[])
{
	bool c = true;

	for(int i = 0;i < 32;i += 1)
	{
		r[i] = ~a[i] & b[i] & c;
		c = c & (~a[i] | b[i]); 
	}
}

int main()
{
	srand(time(NULL));
	bool a[32], b[32], r[32];
	PopulateWord(a);
	PopulateWord(b);
	GE(a,b,r);

	std::cout << "a = " << ToString(a) << "\n";
	std::cout << "b = " << ToString(b) << "\n";
	std::cout << "r = " << ToString(r) << "\n";
	return 0;
}
