//Lab 1 : Statistic
//Team: JO-EL
//Members: Elvis Rodriguez, Jonathan James
//Creation: 10/16/17
#include "Repository.h"
#include <fstream>
using namespace std;

int main()
{
	double x[5];

	if (Tester())
	{
		string values[5] = { "first","second","third","fourth","fifth" };
		for (int i = 0; i < 5; i += 1)
		{
			cout << "Enter the " << values[i] << " value: ";
			cin >> x[i];
		}
	}
	else
	{
		for (int i = 0; i < 5; i += 1)
		{
			x[i] = (i + 1.0);
		}
	}
	string str = stats(x[0], x[1], x[2], x[3], x[4]);
	fstream out;
	out.open("record.txt", fstream::out);
	out << str << "\n";
	out.close();
	cout << "Record has been generated.\n";
	return 0;
}
