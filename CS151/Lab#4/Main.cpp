//Lab 2 : Tic Tac Toe
//Team: JO-EL
//Members: Elvis Rodriguez, Johnathan James
//Creation: 11-13-17
#include "Repository.h"
#include <fstream>
using namespace std;

void DataStore()
{
	fstream out;
	stringstream sout;
	double maxTime, angle = rand() % 89 + 1, velocity = rand() % 60 + 1;

	maxTime = (-2 * velocity * sin(toRad(angle))) / G;

	out.open("Report.dat",fstream::out);

	sout << left;
	sout << setw(20) << "Time (s)" << setw(20) << "Velocity (m/s)"
		<< setw(20) << "Height (m)" << setw(20) << "Displacement (m)" << "\n";

	out << sout.str();
	for(double i = 0;i < maxTime;i += 0.01)
	{
		if((i + 0.01) > maxTime)
			i = maxTime;

		out << stats(velocity,i,angle);
	}

	out.close();
}

int main()
{
	srand(time(NULL));

	if(Tester())
	{
		DataStore();
	}

	return 0;
}
