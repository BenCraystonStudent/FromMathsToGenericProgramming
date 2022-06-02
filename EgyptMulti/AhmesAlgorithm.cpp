#include <iostream>

bool odd(int n)
{
	return n & 0x1;
	//Does a bitwise AND on the least significant bit of of n.
	//If the least significant bit is 1, then the number is odd.
}

int half(int n)
{
	return n >> 1;
}


int AhmesAlgorithm(int n, int a)
{

	if (n == 1)
	{
		return a;
	}

	int result = AhmesAlgorithm(half(n), a + a);

	if (odd(n))
	{
		result = result + a;
	}

	return result;
}

int main()
{
	int x = AhmesAlgorithm(15, 5);
	std::cout << x << std::endl;
	return 0;
}

/*

This algorithm is O(log n):

[log n] + (v(n) - 1) 

where v(n) is the is the numbers of 1s in the binary representation of n.

log n in this case is the number of multiplications of 2 needed.
For instance, 
"How many 2s multiply together to make 8?

Answer: 2 × 2 × 2 = 8, so we had to multiply 3 of the 2s to get 8

So the logarithm (base 2) is 3

Example: What is log (base 5) 625 ... ?
We are asking "how many 5s need to be multiplied together to get 625?"

5 × 5 × 5 × 5 = 625, so we need 4 of the 5s

Answer: log5(625) = 4"

So, 
[log n] + (v(n) - 1) 
here is
3 + 4 - 1 = 6
(or log 3.9 more specifically)
*/