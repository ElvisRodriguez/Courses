#include <iostream>
#include <string>

/******************************************************************************
Form Questions
*******************************************************************************
Q: Which of the following is the onversion of the decimal number 23 in binary?
A: 00010111

Q: What is the binary number 101110110110 in hexadecimal?
A: BB6

Q: Cnvert the decimal number 0.65625 to binary
A: 0.10101

Q: If the number 1221 is in base 3, what is it converted to base 9?
A: 57
******************************************************************************/

std::string ToBinaryString(std::string word)
{
	std::string cvs[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"}, result = "";
	int n = word.length();

	for(int i = 0;i < n;i += 1)
	{
		if(word[i] >= '0' && word[i] <= '9')
		{
			result += cvs[word[i]-'0'];
		}
		else
		{	
			result += cvs[word[i]-'A'+10];
		}
	}
	return result;
}

int main()
{
	std::cout << ToBinaryString("A4") << "\n";
	return 0;
}

