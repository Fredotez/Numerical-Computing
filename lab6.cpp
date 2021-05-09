/***************************************************************************************************************************************************************
Filename:				lab6.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 6
Assignment name:		Lagrange Interpolation
Purpose:				

Write a C\C++ program to implement the Lagrange interpolation for a given set of 
data points using the previous algorithm. Test your program using the following data. 
It is important to check that the value where you will perform the interpolation at, i.e. 
𝑥𝑝, falls in the range between the smallest and largest values of the independent 
variable: 𝑥𝑚𝑖𝑛 < 𝑥𝑝 < 𝑥𝑚𝑎𝑥.

****************************************************************************************************************************************************************/

#include <iostream> 
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {

	int numPoints = 0;
	//int maxValue, minValue;
	double xVal[100], yVal[100];
	double interpolationPoint = 0, interpolationValue = 0, p = 0;

	cout << "Enter number of data:" << endl;
	cin >> numPoints;
	cout << "Enter data: " << endl;

	for (int i = 0; i < numPoints; i++) {

		cout << "x[" << i + 1 << "]:" << endl;
		cin >> xVal[i];
		cout << "y[" << i + 1 << "]:" << endl;
		cin >> yVal[i];

	}

	
	while (true) {

		cout << "Enter interpolation point:" << endl;
		cin >> interpolationPoint;
		if (interpolationPoint < xVal[0] || interpolationPoint > xVal[numPoints - 1]) {
			cout << "Invalid point" << endl;
			//break;
		}
		else {

			for (int i = 1; i < numPoints; i++) {

				p = 1;

				for (int j = 1; j < numPoints; j++) {

					if (i != j) {
						p = p * ((interpolationPoint - xVal[j]) / (xVal[i] - xVal[j]));
					}

				}
				interpolationValue = interpolationValue + p * yVal[i];
			}

			cout << setprecision(3) << fixed << "Interpolated value at " << interpolationPoint << " is " << interpolationValue << endl;
		}
	}

}