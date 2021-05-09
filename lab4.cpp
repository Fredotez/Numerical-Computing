/***************************************************************************************************************************************************************
Filename:				lab4.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 6
Assignment name:		Taylor series Expansion
Purpose:				

Part A: Write a C\C++ program which takes x as input and computes the series for up to 10 
terms. Your program should print the final value of 𝑓(𝑥) = ln 𝑥 around 𝑎 = 1 obtained along 
with the absolute and relative errors.
Your program needs to get the true value of 𝑓(𝑥) = ln 𝑥 using the built-in function in C.
Part B: Run your program for x = 0.5, 1.5, 2.0, and 3.3. Report the results you get for each 
one. How accurate are your results?
Part C: Run your program for the same value of x as in part B but change the number of 
terms to be 100. Report the results you get for each one. How accurate are your results?


****************************************************************************************************************************************************************/

#include<stdio.h>
#include<math.h>

#define _CRT_SECURE_NO_WARNINGS

void taylor(double x) {

    int a = 1;
    int n = 100;
    double taylorCalc = 0;
    double absolute = 0;
    double relative = 0;
    double trueVal = 0;
    int numTerms = 100;

    trueVal = log(x);

    for (n = 1; n <= numTerms; n++) {
        taylorCalc = taylorCalc + (pow(-1, (n - 1)) * (pow((x - a), n) / n));
    }
    
    /*
    absolute error = true value - numerical value
    relative error = absolute error / true value

    */
    absolute = trueVal - taylorCalc;
    relative = absolute / trueVal;

    printf("\nThe number of terms: %d\n", n - 1);

    printf("True value = %lf\n", trueVal);
    printf("Taylor value: %lf\n", taylorCalc);
    printf("Absolute error = %lf\n", absolute);
    printf("Relative error = %lf\n", relative);
}

int main() {
    double c = 0;

    while (1) {
        printf("\nEnter the value of x: ");
        scanf("%lf", &c);
        taylor(c);
    }

    return 0;
}