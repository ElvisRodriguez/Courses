#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Mean.h"
#include "Variance.h"
#include "Zscores.h"
#include "Stats.h"

bool MeanTest()
{
	double nums[] = { 1,2,3,4,5 };
	return (mean(nums[0], nums[1], nums[2], nums[3], nums[4]) == 3.0);
}

bool VarianceTest()
{
	double nums[] = { 1,2,3,4,5 };
	return (variance(nums[0], nums[1], nums[2], nums[3], nums[4]) == 2.0);
}

bool ZscoreTest()
{
	double nums[] = { 1,2,3,4,5 };
	double znum[5];

	for (int i = 0; i < 5; i += 1)
	{
		znum[i] = (nums[i] - 3.0) / sqrt(2.0);
	}

	zscores(nums[0], nums[1], nums[2], nums[3], nums[4]);

	for (int i = 0; i < 5; i += 1)
	{
		if (znum[i] != nums[i])
		{
			return false;
		}
	}

	return true;
}

bool StatsTest()
{
	double nums[] = { 1,2,3,4,5 };
	std::string result, solution ="";

	solution += "For values\n";
	solution += "[1.00,2.00,3.00,4.00,5.00]\n";
	solution += "Mean\n";
	solution += "3.00\n";
	solution += "Standard Deviation\n";
	solution += "1.41\n";
	solution += "Z-scores\n";
	solution += "[-1.41,-0.71,0.00,0.71,1.41]";

	result = stats(nums[0], nums[1], nums[2], nums[3], nums[4]);
	return (result == solution);
}

bool Tester()
{
	bool(*func[4])() = { &MeanTest,&VarianceTest,&ZscoreTest,StatsTest }, result = true;
	std::string functions[4] = { "Mean","Variance","Zscores","Stats" };
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
