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

void LE(bool a[], bool b[], bool r[]) {
	bool ignore = false;
	for (int i = 0; i < 32; i++) {
		r[i] = 0;
		if (a[i] != b[i] && !ignore) {
			ignore = true;
			r[i] = a[i] < b[i] ? 0:1;
		}
	}
}

int main()
{
	srand(time(NULL));
	bool a[32], b[32], r[32];
	PopulateWord(a);
	PopulateWord(b);
	
	std::cout << "a = " << ToString(a) << "\n";
	std::cout << "b = " << ToString(b) << "\n";
	//LE(a,b,r);
	//std::cout << "r = " << ToString(r) << '\n';

	return 0;
}
