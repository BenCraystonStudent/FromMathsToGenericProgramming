#include <iostream>

bool odd(int n)
{
	return n & 0x1;
	//Does a bitwise AND on the least significant bit of of n.
	//If the least significant bit is 1, then the number is odd.
}




int AhmesAlgorithm(int n, int a)
{

	if (n == 1)
	{
		return a;
	}

}