/********************************************************************************************************************
File Name:			     ass2.cpp
Versions:				 1.0
Author:				     Frederic Desjardins
Student Number:			 040941359
Course Name/Number :     Numerical Computing 20F_CST8233_310
Lab sect:				 310
Assignment Name:		 Moore's Law
Assignment #:			 2
Due Date of assignment:  Nov 11 2020
Submission Date:		 Nov 11, 2020
Professor:			     Dr.Hala Own
Purpose:				 Fit data using linear regression least squares method for an exponential function.
********************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <math.h>
#include <vector>

using namespace std;



double	year[50];
double tranCount[50];
int lineCount = 0;
int numElements = 14;


double sumX = 0;
double LogsumY = 0;

double x2 = 0;
double xlogy = 0;

double inputYear = 0;

double a1 = 0;
double a0 = 0;

double incRate = 0;
double transistorCount = 0;


bool openFile(string fileName);
void calculateResults();
void printResults();


void calculateResults() {

	a1 = ((numElements * xlogy) - (sumX * LogsumY)) / ((numElements * x2) - (pow(sumX, 2)));

	a0 = exp((LogsumY / numElements) - a1 * (sumX - (1970 * numElements)) / numElements);

	incRate = (a0 * a1) * exp(a1 * (inputYear - 1970));

	transistorCount = a0 * exp(a1 * (inputYear - 1970));

}

void printResults() {

	cout << "Year = " << inputYear << endl;

	cout << "Transistor Count = " << transistorCount << " transistors / year." << endl;

	cout << "Increment Rate = " << incRate << endl;


}


bool openFile(string fileName) {

	ifstream file;


	file.open(fileName);

	if (!file) {
		cout << "Unable to open file" << endl;
		return false;
		exit(1); // terminate with error
	}
	else {

		string currentLine;

		while (!file.eof()) {

			getline(file, currentLine);
			file >> year[lineCount];
			file >> tranCount[lineCount];
			lineCount++;

		}
		
		file.clear();
		file.seekg(0);

		while (!file.eof()) {

			getline(file, currentLine);
			cout << currentLine << endl;

		}
		
	

		for (int i = 0; i < numElements; i++) {

			sumX += year[i];
			LogsumY += log(tranCount[i]);
			x2 += pow((year[i]), 2);
			xlogy += ((year[i]) * log(tranCount[i]));
		}
		return true;
	}

	file.close();

}


int main()
{
	// int variable to get the user input
	int optionMain = 0;
	int optionSecond = 0;

	string fileName;


	
	while (true)
	{
		cout << "MENU" << endl;
		cout << "1. Exponential Fit" << endl;
		cout << "2. Quit" << endl;
		//getting the user input
		cin >> optionMain;

		if (optionMain == 1) {

			cout << "Please enter the name of the file to open: " << endl;
			cin >> fileName;

			if (openFile(fileName)) {

				calculateResults();
				cout << "There are " << numElements << " records." << endl;

				cout << setprecision(3);
				cout << scientific << "Linear Regression Fit: transistor count = " << a0 << "*exp(" << a1 << "(year - 1970))" << endl;

				while (true)
				{
					cout << "MENU" << endl;
					cout << "1. Extrapolation" << endl;
					cout << "2. Quit" << endl;
					//getting the user input
					cin >> optionSecond;

					if (optionSecond == 1) {
						cout << "Please enter the year to extrapolate to: " << endl;
						cin >> inputYear;
						calculateResults();
						printResults();

					}
					else if (optionSecond == 2) {
						cout << "LEAST_SQUARES LINEAR REGRESSION" << endl;
						break;
					}
					else {
						cout << "Invalid input, please try again." << endl;
					}
				}

			}

		}
		else if (optionMain == 2){

			cout << "Thanks for using Frederic's Moore's Law program." << endl;
			exit(1);

		}
		else {
			cout << "Invalid input, please try again." << endl;
		}

	}
	
	return 0;
}
