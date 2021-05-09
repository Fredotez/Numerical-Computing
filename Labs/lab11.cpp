/***************************************************************************************************************************************************************
Filename:				lab11.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 11
Assignment name:		Numerical Differentiation
Purpose:				C++ Program that uses the forward, backward and centered finite difference scheme to approximate the first derivative of the function
****************************************************************************************************************************************************************/

#include <iostream> 
#include <iomanip>

using namespace std;

// exact solution : f(x) = x sin(x^2) + 1

// approximate the first derivative : f'(x) = sin(x^2) + 2x^2cos(x^2)

double x = 0;
double y;
double h = 0.25;

double exactDerValue;
double centeredDif;
double forwardDif;
double backwardDif;

double f(double x);
double fp(double x);

void numDif() {

	cout << "x" << "\t" << "y" << "\t" << "Exact derivative" << "\t" << "Centered" << "\t" << "Forward" << "\t\t" << "Backward" << endl;

	// loop from 0 to 4
	for (double i = 0; i <= 4; i += h) {

		x = i;
		y = f(x);		

		//Exact derivative
		exactDerValue = fp(x);

		// centered difference, x+h & x-h
		centeredDif = (f(x + h) - f(x - h)) / (2 * h);

		// forward difference, x+h
		forwardDif = (f(x + h) - f(x)) / h;

		// backward difference, x-h
		backwardDif = (f(x) - f(x - h)) / h;

		// Checks if parameters are within bounds
		if ((x + h) > 4) {
			forwardDif = NULL;
			centeredDif = NULL;
		} 

		if ((x - h) < 0) {
			backwardDif = NULL;
			centeredDif = NULL;
		}
		//

		//prints values
		cout << fixed;
		cout << setprecision(3);
		cout << x << "\t" << y << "\t" << exactDerValue << "\t\t" << centeredDif << "\t\t\t" << forwardDif <<  "\t\t\t" << backwardDif << endl;

	}


}

// calculate f(x)
double f(double x) {

	return (x * sin(pow(x, 2)) + 1);
}

// calculate derivative of f(x)
double fp(double x) {
	return (sin(pow(x, 2)) + (2 * (pow(x, 2))) * (cos(pow(x, 2))));
}

//main function, calls numDif()
int main() {

	numDif();
	return 0;
}
