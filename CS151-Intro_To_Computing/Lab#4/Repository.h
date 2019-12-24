#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Height.h"
#include "Displacement.h"
#include "Stats.h"
#include "Velocity.h"

bool HeightTest()
{
	bool result = (abs(height(40,5,45) - 18.92) < 0.01) && (abs(height(98,10,90) - 490) < 0.01);
	return result;
}

bool DisplacementTest()
{
	bool result = (abs(displacement(40,10,45) - 282.84) < 0.01);
	result = result && (abs(displacement(98,5,90) - 0) < 0.01);
	result = result && (abs(displacement(40,3,0) - 120.0) < 0.01);
	return result;
}

bool VelocityTest()
{
	bool result = (abs(velocity(40,2,45) - 8.68) < 0.01);
	result = result && (abs(velocity(98,5,90) - 49) < 0.01);
	result = result && (abs(velocity(40,3,0) - -29.4) < 0.01);
	return result;
}

bool StatsTest()
{
	std::stringstream str;
	str << std::left << std::fixed << std::setprecision(2);
	str << std::setw(20) << 2.00;
	str << std::setw(20) <<	0.40;
	str << std::setw(20) <<	20.40;
	str << std::setw(20) << 69.28 << "\n";
	std::string result = str.str();
	return (stats(40,2,30) == result);
}


bool Tester()
{
	bool(*func[4])() = { &HeightTest,&DisplacementTest,&VelocityTest,&StatsTest}, result = true;

	std::string functions[4] = { "Height","Displacement","Velocity","Stats"};
	for (int i = 0; i < 4; i += 1)
	{
		std::cout << functions[i] << " Test ";
		std::cout << ((func[i]()) ? ("has passed.\n") : ("has failed.\n"));
		if (!func[i]())
		{
			result = false;
		}
	}

	std::cout << "\n";
	return result;
}

#endif 
