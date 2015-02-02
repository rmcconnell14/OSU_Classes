/*********************************************************************
** Program Filename: fibonacci.cpp
** Author: Rachael McConnell
** Date: 12/2/2014
** Description: This program compares the runtime performance of 3 algorithms, each calculating the Fibonacci sequence in a different way.
** Input: User inputs how many numbers in the Fibonacci sequence they would like to see.
** Output: The Fibonacci sequence requested is output, along with the runtime for each algorithm.
********************************************************************/

//#include "stdafx.h"
#include "fib.h"

int fibonacciRecursive(int n)
{
	if (n <= 2)
		return 1;
	else
		return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


int fibonacciIterative(int n)
{
	if (n < 2)
		return 1;
	int i, last = 1, nextToLast = 1, result = 1;
	for (i = 3; i <= n; i++)
	{
		result = last + nextToLast;
		nextToLast = last;
		last = result;
	}
	return result;
}


int fibonacciSingle(int n, int a, int b)
{
	if (n == 1)
		return a;
	else
		return fibonacciSingle(n - 1, a + b, a);
}
