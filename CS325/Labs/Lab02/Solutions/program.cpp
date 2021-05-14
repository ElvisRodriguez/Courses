#include <iostream>
#include <string>
#include <vector>

std::string ToBinaryString(std::vector<bool>& word)
{
	int n = word.size();
	std::string result = "";

	for(int i = 0;i < n;i += 1)
	{
		result += ((word[i])?('1'):('0'));
	}
	return result;
}

int main()
{
	std::vector<bool> a = {false,true,true,false,false,true};
	std::cout << ToBinaryString(a) << "\n";
	return 0;
}
	
