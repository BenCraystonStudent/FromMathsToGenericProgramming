#include <iostream>

int multiply_by_15(int a)
{
	int b = (a + a) + a;
	int c = b + b;
	return (c + c) + b;
}

int multiplayUnknown(int a)
{
	int b = (a + a + a) + a;
	int c = b + b;
	return (c + c) + b;
}

//Uses 5 additions (better than Ahmes)
//"Such a sequnce of additions is called an addition chain."
//"Here we have discovered an optimal additional chain for 15."
//"Nevertheless, Ahmes's algorithm is good enough for most purposes."