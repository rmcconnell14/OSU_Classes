/*****************************************************************************
** CS261- Assignment 2 - calc.c
** Name: Rachael McConnell
** Date : Jan 22, 2015
** Solution description : This program acts as a RPN calculator. The program reads in a sequence of numbers and operators from the command line and displays the result.
** Input : Input is taken from the command line
** Output : The result of the given numbers and operators.
*****************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "dynamicArray.h"

#define PI 3.14159265
#define E 2.7182818

/* param: s the string
param: num a pointer to double
returns: true (1) if s is a number else 0 or false.
postcondition: if it is a number, num will hold
the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;
	if (strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if ((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their sum is pushed back onto the stack.
*/
void add(struct DynArr *stack)
{
	double val1, val2, sum;
	assert(stack != NULL);
	assert(sizeDynArr(stack) != 1);
	val1 = topDynArr(stack);
	popDynArr(stack);
	val2 = topDynArr(stack);
	popDynArr(stack);
	sum = val1 + val2;
	addDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double val1, val2, difference;
	assert(stack != NULL);
	assert(sizeDynArr(stack) != 1);
	val1 = topDynArr(stack);
	popDynArr(stack);
	val2 = topDynArr(stack);
	popDynArr(stack);
	difference = val2 - val1;
	addDynArr(stack, difference);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double val1, val2, quotient;
	assert(stack != NULL);
	assert(sizeDynArr(stack) != 1);
	val1 = topDynArr(stack);
	popDynArr(stack);
	val2 = topDynArr(stack);
	popDynArr(stack);
	quotient = val2 / val1;
	addDynArr(stack, quotient);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
the multiplication result is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	double val1, val2, total;
	assert(stack != NULL);
	assert(sizeDynArr(stack) != 1);
	val1 = topDynArr(stack);
	popDynArr(stack);
	val2 = topDynArr(stack);
	popDynArr(stack);
	total = val1 * val2;
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least two elements
post: the top two elements are popped and
the result of the first num to the power of the
second num is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
	double val1, val2, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	val2 = topDynArr(stack);
	popDynArr(stack);
	total = pow(val2, val1);
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top element is popped and
its square is pushed back onto the stack.
*/
void square(struct DynArr *stack)
{
	double val1, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	total = val1*val1;
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top element is popped and
the top element cubed is pushed back onto the stack.
*/
void cube(struct DynArr *stack)
{
	double val1, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	total = val1 * val1 * val1;
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top element is popped and
the absolute value is pushed back onto the stack.
*/
void absVal(struct DynArr *stack)
{
	double val1, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	total = abs(val1);
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top element is popped and
the square root of the top element is pushed
back onto the stack.
*/
void sqRt(struct DynArr *stack)
{
	double val1, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	total = sqrt(val1);
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top element is popped and
the exponential is pushed back onto the stack.
*/
void expon(struct DynArr *stack)
{
	double val1, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	total = exp(val1);
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top element is popped and
its natural log is pushed back onto the stack.
*/
void natLog(struct DynArr *stack)
{
	double val1, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	total = log(val1);
	addDynArr(stack, total);
}

/*	param: stack the stack being manipulated
pre: the stack contains at least one element
post: the top element is popped and
its log is pushed back onto the stack.
*/
void logFunc(struct DynArr *stack)
{
	double val1, total;
	assert(stack != NULL);
	val1 = topDynArr(stack);
	popDynArr(stack);
	total = log10(val1);
	addDynArr(stack, total);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	double dNumber = 0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for (i = 1; i < numInputTokens; i++)
	{
		s = inputString[i];

		//Call functions based on the corresponding operator
		if (strcmp(s, "+") == 0)		
			add(stack);
		else if (strcmp(s, "-") == 0)
			subtract(stack);
		else if (strcmp(s, "/") == 0)
			divide(stack);				
		else if (strcmp(s, "x") == 0)
			multiply(stack);
		else if (strcmp(s, "^") == 0)
			power(stack);
		else if (strcmp(s, "^2") == 0)
			square(stack);
		else if (strcmp(s, "^3") == 0)
			cube(stack);
		else if (strcmp(s, "abs") == 0)
			absVal(stack);
		else if (strcmp(s, "sqrt") == 0)
			sqRt(stack);
		else if (strcmp(s, "exp") == 0)
			expon(stack);
		else if (strcmp(s, "ln") == 0)
			natLog(stack);
		else if (strcmp(s, "log") == 0)
			logFunc(stack);
		else
		{
			//check if s is a number and pass to function
			if (isNumber(s, &dNumber) == 1){
				//push number on the stack
				pushDynArr(stack, dNumber);
			}
			else if (strcmp(s, "pi") == 0){
				dNumber = PI;
				//push PI on the stack
				pushDynArr(stack, dNumber);
			}
			else if (strcmp(s, "e") == 0){
				dNumber = E;
				//push E on the stack
				pushDynArr(stack, E);
			}
			else
			{
				printf("Error: that is not a valid number.");
			}

		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below)
	* (1) Check if everything looks OK and produce an error if needed.
	* (2) Store the final value in result and print it out.
	*/
	assert(stack != NULL);
	assert(sizeDynArr(stack) == 1);
	result = topDynArr(stack);
	popDynArr(stack);
	deleteDynArr(stack);
	printf("\nRESULT = %lf\n", result);
	return result;
}

int main(int argc, char** argv)
{
	// argv- arguments
	// argc- number of operands
	if (argc == 1)
		return 0;

	calculate(argc, argv);
	return 0;
}

