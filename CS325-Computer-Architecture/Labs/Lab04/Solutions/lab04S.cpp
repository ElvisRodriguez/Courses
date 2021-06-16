#include <iostream>
#include <string>

/******************************************************************************
Q: How many digits will be in the conversion of the base 8 number 6123167235
to binary
A: 3 * 10 = 30 digits

Q: What is a nibble?
A: A group of 4 bits (half a byte)

Q: State the digits of a base 12 number system and convert the decimal number
132 to base 12.
A: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B; B0

Q: Convert the hexadecimal number BAD.F to decimal.
A: 11 x 16^2 + 10 x 16 + 13 x 1 + 15 x 16^(-1) = 2989.9375
******************************************************************************/

std::string ToBinaryMantissa(double radix)
{
	std::string result = "";

	if(radix > 0 && radix < 1)
	{
		int cnt = 0, bdigit;
		result += "0.";

		while(cnt < 10 && radix != 0)
		{
			bdigit = 2 * radix;
			result += std::to_string(bdigit);
			radix = 2 * radix - bdigit;
			cnt += 1;
		}
	}
	return result;
}

int main()
{
	std::cout << ToBinaryMantissa(0.625) << "\n";
	return 0;
}
			
