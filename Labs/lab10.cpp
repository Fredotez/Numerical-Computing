/***************************************************************************************************************************************************************
Filename:				lab10.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 10
Assignment name:		Non-Linear Regression
Purpose:				Write C\C++ program that Find the model of progress of a chemical reaction.
****************************************************************************************************************************************************************/


#include <iostream> 

using namespace std;

void nonLinearRegression(int dataPoints) {


	double* x = new double[dataPoints];
	double* y = new double[dataPoints];


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

	/*
	for (int i = 0; i < dataPoints; i++) {
		cout << "x" << i << ": " << x[i] << endl;
		cout << "y" << i << ": " << y[i] << endl;
	}
	*/
	double LogsumX = 0;
	double LogsumY = 0;

	double sumX = 0;
	double sumY = 0;

	double Logx2 = 0;
	double Logxy = 0;

	for (int i = 0; i < dataPoints; i++) {

		sumX += x[i];
		sumY += y[i];

		LogsumX += log(x[i]);
		LogsumY += log(y[i]);

		Logx2 += pow(log(x[i]), 2);
		Logxy += (log(x[i]) * log(y[i]));

	}

	double meanX = sumX / dataPoints;
	double meanY = sumY / dataPoints;

	double a1 = ((dataPoints * Logxy) - (LogsumX * LogsumY)) / ((dataPoints * Logx2) - (pow(LogsumX, 2)));
	double a0 = exp((LogsumY - (a1 * LogsumX)) / dataPoints);

	cout << "The linear fit line is of the form: " << endl;

	cout << "y = " << a0 << " * x^" << a1 << endl;

}

int main() {

	int dataPoints = 1;

	while (dataPoints) {

		if (dataPoints > 1) {
			break;
		}
		cout << "Enter the no. of data pairs to be entered (0 to quit): " << endl;
		cin >> dataPoints;
		nonLinearRegression(dataPoints);
	}



}