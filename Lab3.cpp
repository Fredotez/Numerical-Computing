/***************************************************************************************************************************************************************
Filename:				lab3.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 6
Assignment name:		IEEE Floating Point Representation
Purpose:				

The objective of this lab is to get familiar with the following:
1- Overflow and Underflow in floating Point Representation 
2- Absolute and Relative Error

****************************************************************************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES

int factorial(int n)
{
	int i;
	unsigned long long factorial = 1;
	//printf("Enter an integer: ");
	//scanf("%d", &n);
	// show error if the user enters a negative integer
	if (n < 0)
		printf("Error! Factorial of a negative number doesn't exist.");
	else
	{
		for (i = 1; i <= n; ++i)
		{
			factorial *= i; // factorial = factorial*i;
		}
		//printf("Factorial of %d = %llu\n", n, factorial);
	}
	return factorial;
}

int overflow()
{
	int i;
	float n, x;
	n = 1.0;
	for (i = 0; i <= 127; i++)
	{
		n = n * 2.0;
		x = 1.0 / n;
		printf("%d %e %E\n", i, x, n);
	}
	return 0;
}

float approximation(int n) {
	
	float EulerConstant = exp(1.0);
	double approx = pow((n / EulerConstant), n) * (sqrt(2* acos(-1.0)*n));
	return approx;
}

float absoluteError(float fact, float approx) {

	float absolute = fact - approx;
	return absolute;
}

float relativeError(float fact, float absoluteError) {
	
	float absolute = absoluteError / fact;
	return absolute;
}

int main() {

	overflow();

	for (int i = 0; i <= 10; i++) {
		
		float fact = factorial(i);
		float approx = approximation(i);
		float absolute = absoluteError(fact, approximation(i));
		float relative = relativeError(fact, absolute);
		printf("N: %d, ", i); 
		printf("Factorial: %f, ", fact); 
		printf("Approximation: %f, ", approx); 
		printf("Absolute Error: %f, ", absolute); 
		printf("Relative Error: %f\n", relative);
	}
}