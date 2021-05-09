/***************************************************************************************************************************************************************
Filename:				ass3.cpp
Version: 				1.0
Author:					Frederic Desjardins
Student No:  			040941359
Course Name/Number:		CST 8233 (Numerical Computing)
Lab Secttion: 			311
Assignment #:			3
Assignment name:		Transient-Response Analysis of 1st Order Systems
Due Date:				6 December 2020
Submission Date:		4 December 2020
Professor:				Dr.Hala Own
Purpose:				Find the solution of 1st order Ordinary Differential Equations (ODE) using well known methods; namely, Euler’s, Runge-Kutta 1,2,3,and 4.
****************************************************************************************************************************************************************/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip> 
#include <math.h>

using namespace std;

double e = 2.71828182845904523536;

using namespace std;

double exactTemp = 0;
double estimatedTemp = 0;
double percentageError = 0;

double initialTemp = 3;

double tempVar;
double stepSize;

double t;
double tStep;

void resetVariables() {

	 exactTemp = 0;
	 estimatedTemp = 0;
	 percentageError = 0;

	 initialTemp = 3;

	 tempVar = 0;
	 stepSize = 0;

	 t = 0;
	 tStep = 0;


}


void euler() {

	tempVar = initialTemp;

	cout << "Choose step size h (0.8, 0.2, 0.05)" << endl;
	cin >> stepSize;

	if (stepSize != 0.8 && stepSize != 0.2 && stepSize != 0.05) {
		cout << "Invalid step size, h must be (0.8, 0.2, 0.05)" << endl;
		return;
	}

	cout << "Time(second)\tExact Temp(C)\tEstimated Temp(C)\tPercentage Error(%)" << endl;

	for (t = 0; t <= 2; t += stepSize) {

		tStep += stepSize;

		if (tStep > 2.0001) { break; }

		exactTemp = (0.1 * cos(4 * tStep)) + (0.2 * sin(4 * tStep)) + (2.9 * pow(e, -2 * tStep));
		

		estimatedTemp = tempVar + stepSize * (cos(4 * t) - (2 * tempVar));
	

		percentageError = (exactTemp - estimatedTemp) / exactTemp * 100;
	
		setprecision(3);
		cout << tStep << "\t\t";
		cout << exactTemp << "\t\t";
		cout << estimatedTemp << "\t\t\t";
		cout << abs(percentageError) << endl;
		

		tempVar = estimatedTemp;


	}

	resetVariables();
}


void rungeKutta(int order) {

	tempVar = initialTemp;
	double kutta1, kutta2, kutta3, kutta4, increment = 0;

	cout << "Choose step size h (0.8, 0.2, 0.05)" << endl;
	cin >> stepSize;

	if (stepSize != 0.8 && stepSize != 0.2 && stepSize != 0.05) {
		cout << "Invalid step size, h must be (0.8, 0.2, 0.05)" << endl;
		return;
	}

	cout << "Time(second)\tExact Temp(C)\tEstimated Temp(C)\tPercentage Error(%)" << endl;

	for (t = 0; t <= 2; t += stepSize) {

		tStep += stepSize;

		if (tStep > 2.0001) { break; }

		exactTemp = (0.1 * cos(4 * tStep)) + (0.2 * sin(4 * tStep)) + (2.9 * pow(e, -2 * tStep));
		kutta1 = stepSize * (cos(4 * t) - (2 * tempVar));

		switch (order) {
			case 2:
				
				kutta2 = stepSize * (cos(4 * (t + stepSize )) - (2 * (tempVar + kutta1)));
				increment = (kutta1 + kutta2) / 2;
				break;
			case 3:
				
				kutta2 = stepSize * (cos(4 * (t + stepSize / 2)) - (2 * (tempVar + kutta1 / 2)));
				kutta3 = stepSize * (cos(4 * (t + stepSize / 2)) - (2 * (tempVar - kutta1 + 2*kutta2)));
				increment = (kutta1 + 4 * kutta2 + kutta3) / 6;
				break;
			case 4:
				
				kutta1 = stepSize * (cos(4 * t) - (2 * tempVar));
				kutta2 = stepSize * (cos(4 * (t + stepSize / 2)) - (2 * (tempVar + kutta1 / 2)));
				kutta3 = stepSize * (cos(4 * (t + stepSize / 2)) - (2 * (tempVar + kutta2 / 2)));
				kutta4 = stepSize * (cos(4 * (t + stepSize)) - (2 * (tempVar + kutta3)));
				increment = (kutta1 + 2 * kutta2 + 2 * kutta3 + kutta4) / 6;
				break;
		}

		estimatedTemp = tempVar + increment;

		percentageError = (exactTemp - estimatedTemp) / exactTemp * 100;

		cout.precision(3);
		
		cout << tStep << "\t\t";
		cout << exactTemp << "\t\t";
		cout << estimatedTemp << "\t\t\t";
		cout << abs(percentageError) << endl;

		tempVar += increment;

	}

	resetVariables();
}


int main() {

	int menuOption;

	while (true)
	{
		cout << "MENU" << endl;
		cout << "1.  Euler's Method" << endl;
		cout << "2.  Runge-Kutta 2nd Order Method" << endl;
		cout << "3.  Runge-Kutta 3rd Order Method" << endl;
		cout << "4.  Runge-Kutta 4th Order Method" << endl;
		cout << "5.  Exit" << endl;
		
		cin >> menuOption;

		switch (menuOption) {

		case 1:
			euler();
			break;

		case 2:			
		case 3:			
		case 4:
			rungeKutta(menuOption);
			break;
		case 5:
			cout << "Exiting....." << endl;;
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}

	}

	return 0;

}