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
	};
};

//Uses multiple recursive calls, accumulating r to dictate the number of calls made

	  public: int MultiplyAccumulator1(int r, int n, int a)
	  {
		  if (n == 1)
		  {
			  return r + a;
		  }

		  if (odd(n))
		  {
			  r = r + a;
		  }

		  return MultiplyAccumulator1(r, half(n), a + a);
	  };

//modifies the value of r before recursion, making the lagortihm "tail recursive" - recursion occurs ONLY
//in the return value.

	  public: int MultiplyAccumulator2(int r, int n, int a)
	  {
		  if (odd(n))
		  {
			  r = r + a;
			  if (n == 1)
			  {
				  return r;
			  }
		  }
		  return MultiplyAccumulator2(r, half(n), a + a);
	  };
//same sort of idea, n is rarely 1 and if n is even, no point checking to see if its 1
//just a condensed version of the above really with emphasis on tail recursion
//"STRICTLY TAIL RECURSIVE PROCEDURE: a procedure in which all the tail recursive calls are done
//with the formal parameters of the procedure being the corresponding arguments."

/*
Here's a tail-recursive version of the same function:

function tailrecsum(x, running_total = 0) {
    if (x === 0) {
        return running_total;
    } else {
        return tailrecsum(x - 1, running_total + x);
    }
}

Here's the sequence of events that would occur if you called tailrecsum(5), (which would effectively be tailrecsum(5, 0), because of the default second argument).

tailrecsum(5, 0)
tailrecsum(4, 5)
tailrecsum(3, 9)
tailrecsum(2, 12)
tailrecsum(1, 14)
tailrecsum(0, 15)
15

In the tail-recursive case, with each evaluation of the recursive call, the running_total is updated.
			
*/

public: int MultiplyAccumulator3(int r, int n, int a)
{
	if (odd(n))
	{
		r = r + a;
		if (n == 1)
		{
			return r;
		}
	}
	n = half(n);
	a = a + a;
	return MultiplyAccumulator3(r, n, a);
};

	  //this is lovely

//"Now it is easy to convert this to an iterative program by replacing the tail recursion with a while(true) construct"

public: int MultiplyAccumulator4(int r, int n, int a)
{
	while (true)
	{
		if (odd(n))
		{
			r = r + a;
			if (n == 1)
			{
				return r;
			}
		}
		n = half(n);
		a = a + a;
	}
};

//"With our newly optimised multiply-accumulate function, we can write a new version of multiply.
//"Our new version will invoke our multiply-accumulate helperm function:

public: int Multiply2(int n, int a)
{
	if (n == 1)
	{
		return a;
	}
	return MultiplyAccumulator4(a, n - 1, a);
};

//does good work except when n is even as subtracting the 1 means that
//MultiplyAccumulator4 will be called with an odd number, making extra work

public: int Multiply3(int n, int a)
{
	while (!odd(n))
	{
		a = a + a;
		n = half(n);
	}
	if (n == 1)
	{
		return a;
	}
	return MultiplyAccumulator4(a, n - 1, a);
};

//now we're doing an unnecessary test in MultiplyAccumulator4 for odd(n)
//because we're calling it with an even number!
//therefore the final version will half and double the argument before we call it

public: int Multiply4(int n, int a)
{
	while (!odd(n))
	{
		a = a + a;
		n = half(n);
	}
	if (n == 1)
	{
		return a;
		//even(n - 1) -> n - 1 != 1
	}
	return MultiplyAccumulator4(a, half(n - 1), a + a);
};
};