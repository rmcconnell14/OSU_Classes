/*********************************************************************
** Program Filename: Lab10.cpp
** Author: Rachael McConnell
** Date: 12/2/2014
** Description: This program compares the runtime performance of 3 algorithms, each calculating the Fibonacci sequence in a different way. 
** Input: User inputs how many numbers in the Fibonacci sequence they would like to see.
** Output: The Fibonacci sequence requested is output, along with the runtime for each algorithm.
********************************************************************/

//#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include "fib.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	int numFib = 0;

	cout << "How many Fibonacci numbers would you like to see? (Enter a number >=1)\n";
	cin >> numFib;
	while (!cin || numFib < 1)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Please enter a valid number: (1+) ";
		cin >> numFib;
	}
	cout << endl;

	cout << "Recursive (Two recursive function calls):\n ";
	clock_t t = clock();
	
	//call the recursive fibonacci sequence function (two recursive calls)
	for (int i = 1; i < numFib+1; i++)
	{
		cout << fibonacciRecursive(i) << " ";
	}

	t = clock() - t;
	cout << "\nIt took "  << ((float)t / CLOCKS_PER_SEC) << " seconds." << endl;
	cout << endl;


	cout << "Recursive (Only one recursive function call): \n";
	clock_t t2 = clock();

	//call the recursive fibonacci sequence function (only one recursive call)
	for (int i = 1; i < numFib+1; i++)
	{
		cout << fibonacciSingle(i, 1, 0) << " ";
	}
	t2 = clock() - t2;
	cout << "\nIt took " << ((float)t2 / CLOCKS_PER_SEC) << " seconds." << endl;
	cout << endl;


	cout << "Iterative: \n";
	clock_t t3 = clock();

	//call the iterative fibonacci sequence function
	for (int i = 1; i < numFib+1; i++)
	{
		cout << fibonacciIterative(i) << " ";
	}
	t3 = clock() - t3;
	cout << "\nIt took " << ((float)t3 / CLOCKS_PER_SEC) << " seconds." << endl;
	cout << endl;

	return 0;
}
