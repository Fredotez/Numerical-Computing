/***************************************************************************************************************************************************************
Filename:				lab9.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 9
Assignment name:		Simple Linear Regression
Purpose:				Write a C/C++ program to implement the simple linear regression algorithm.
						The program asks the user to input the data then prints the predicted equation.
****************************************************************************************************************************************************************/


#include <iostream> 
     
using namespace std;

void linearRegression(int dataPoints) {


	float* x = new float[dataPoints];
	float* y = new float[dataPoints];


	cout << "Enter x axis values" << endl;
	for (int i = 0; i < dataPoints; i++) {
		cout << "x" << i << ": " << endl;
		cin >> x[i];
		
	}

	cout << "Enter y axis values" << endl;
	for (int i = 0; i < dataPoints; i++) {
		cout << "y" << i << ": " << endl;
		cin >> y[i];
	}

	for (int i = 0; i < dataPoints; i++) {
		cout << "x" << i << ": " << x[i] << endl;
		cout << "y" << i << ": " << y[i] << endl;
	}

	float sumX = 0;
	float sumY = 0;

	float Ex2 = 0;
	float Exy = 0;


	for (int i = 0; i < dataPoints; i++) {

		sumX += x[i];
		sumY += y[i];

		Ex2 += pow(x[i], 2);
		Exy += (x[i] * y[i]);


	}

	cout << "Sum of X: " << sumX << " Sum of Y: " << sumY << " Ex2: " << Ex2 << " Exy: " << Exy << endl;


	float a1 = ((dataPoints * Exy) - (sumX * sumY)) / ((dataPoints * Ex2) - (pow(sumX,2)));
	float a0 = (sumY - (a1 * sumX));

	cout << "S.no \t x \t y(observed) \t y(fitted)" << endl;

	for (int i = 0; i < dataPoints; i++) {

		cout << i+1 << ". \t " << x[i] << " \t " << y[i] << " \t " << a1 * x[i] + a0 << endl;

	}

	cout << "The linear fit line is of the form: " << endl;	

	cout << "y = " << a1 << "x + " << a0 << endl;

}

int lab9() {

	int dataPoints = 1;

	while (dataPoints) {

		if (dataPoints > 1) {
			break;
		}
		cout << "Enter the no. of data pairs to be entered (0 to quit): " << endl;
		cin >> dataPoints;
		linearRegression(dataPoints);
	}

	return 0;

}