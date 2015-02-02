/*********************************************************************
** Program Filename: fibonacci.h
** Author: Rachael McConnell
** Date: 12/2/2014
** Description: This program compares the runtime performance of 3 algorithms, each calculating the Fibonacci sequence in a different way.
** Input: User inputs how many numbers in the Fibonacci sequence they would like to see.
** Output: The Fibonacci sequence requested is output, along with the runtime for each algorithm.
********************************************************************/

//#include "stdafx.h"

#ifndef FIB_H
#define FIB_H

//http://www.programmingincpp.com/recursive-function-versus-non-recursive-function.html
//for the double recursive and iterative functions

//compute nth Fibonacci number by using recursion
int fibonacciRecursive(int n);

//compute nth Fibonacci number using a loop
int fibonacciIterative(int n);

//http://stackoverflow.com/questions/15537432/convert-recursion-to-tail-recursion
int fibonacciSingle(int n, int a = 1, int b = 0);

#endif
