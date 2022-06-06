#include <iostream>

class Ahmes {

public: bool odd(int n)
{
	return n & 0x1;
	//Does a bitwise AND on the least significant bit of of n.
	//If the least significant bit is 1, then the number is odd.
};

public:	int half(int n)
{
	return n >> 1;
	//shifts the bits to the right by 1 place
	//effectively halves the number although not decimally of course
	//rounds down (i think)
};


public:	int AhmesAlgorithm(int n, int a)
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
};
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

public: int multiply_by_15(int a)
{
	int b = (a + a) + a;
	int c = b + b;
	return (c + c) + b;
};

	  //Uses 5 additions (better than Ahmes)
//"Such a sequnce of additions is called an addition chain."
//"Here we have discovered an optimal additional chain for 15."
//"Nevertheless, Ahmes's algorithm is good enough for most purposes."

public: int MultiplyBy20(int a)
{
	int b = (a + a + a) + (a);
	int c = b + b;
	return (c + c) + b;
};

public: int MultiplyBy25(int a)
{
	int b = (a + a + a + a) + a;
	int c = b + b;
	return (c + c) + b;
};

public: int MultiplyAccumulator0(int r, int n, int a)
{
	if (n == 1)
	{
		return r + a;
	}
	if (odd(n))
	{
		return MultiplyAccumulator0(r + a, half(n), a + a);
	}
	else {
		return MultiplyAccumulator0(r, half(n), a + a);
	}
};

	  //Uses multiple recursive calls, accumulating r to dictate the number of calls made

};