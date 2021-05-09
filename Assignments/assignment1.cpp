/**********************************************************************
Filename: ass1.cpp
Author: Frederic Desjardins
Student No: 040141359
Course Name/Number: Numerical Computing CST8233
Lab Sect: 310
Assignment #: 1
Assignment name: Maclaurin Series Application
Due Date: October 11 2020
Submission Date: October 10 2020
Professor: Dr. Hala Own
Purpose: Determine the Maclaurin Series approximation to as a power series in
1 / (sqrt(1 - x * x))
*********************************************************************/


#include <iostream>
#include <iomanip> 

using namespace std;

void taylor(int terms, double range) {

	double x = 0;
	double exactValue = 0;
	double absoluteError = 0;
	double relativeError = 0;
	double maclaurin = 0;
	double truncation = 0;
	double truncationError = 0;
	double y = range / 10;

	cout << "B" << setw(20) << "V(B) Series" << setw(20) << "V(B) exact" << setw(20) << "Relative Error" << setw(20) << "%RSerE" << endl;
	cout << setprecision(11);

	for (int i = 0; i < 11; i++) {

		exactValue = 1 / (sqrt(1 - x * x));

		if (terms == 1) {
			maclaurin = 1 + (x * x) * 1 / 2;
		}
		else if (terms == 2) {
			maclaurin = 1 + (x * x) * 1 / 2;
			truncation = (x * x * x * x) * 3 / 8;
		}
		else if (terms == 3) {
			maclaurin = 1 + (x * x) * 1 / 2 + (x * x * x * x) * 3 / 8;
			truncation = (x * x * x * x * x * x) * 5 / 16;
		}
		else if (terms == 4) {
			maclaurin = 1 + (x * x) * 1 / 2 + (x * x * x * x) * 3 / 8 + (x * x * x * x * x * x) * 5 / 16;
			truncation = (x * x * x * x * x * x * x * x) * 35 / 128;
		}
		else if (terms == 5) {
			maclaurin = 1 + (x * x) * 1 / 2 + (x * x * x * x) * 3 / 8 + (x * x * x * x * x * x) * 5 / 16 + (x * x * x * x * x * x * x * x) * 35 / 128;
			truncation = (x * x * x * x * x * x * x * x * x * x) * 63 / 256;
		}
		else if (terms == 6) {
			maclaurin = 1 + (x * x) * 1 / 2 + (x * x * x * x) * 3 / 8 + (x * x * x * x * x * x) * 5 / 16 + (x * x * x * x * x * x * x * x) * 35 / 128 + (x * x * x * x * x * x * x * x * x * x) * 63 / 256;
			truncation = (x * x * x * x * x * x * x * x * x * x * x * x) * 231 / 1024;
		}

		//trunk error = trunk / exact;
		//relative error = absolute error / valeur exact

		if (exactValue == 0) {
			absoluteError = 0;
			relativeError = 0;
		}
		else {
			absoluteError = exactValue - maclaurin;
			relativeError = absoluteError / exactValue;
		}
		truncationError = 100 * abs(truncation / maclaurin);
		cout << x << setw(20) << maclaurin << setw(20) << exactValue << setw(20) << relativeError << setw(20) << truncationError << endl;
		x += y;
	}
}

int main() {

	int choice;

	while (1) {

		cout << "[1] Evaluate series" << endl;
		cout << "[2] Quit" << endl;

		cin >> choice;

		if (choice == 1) {
			int terms;
			double range;
			cout << "Please enter the number of (non-zero) terms in the series (1,2,3,4,5,6): " << endl;
			cin >> terms;
			if (terms > 1 && terms < 6) {

				cout << "Please enter the range of B to evaluate in 10 increments (0.0 < B <= 0.9): " << endl;
				cin >> range;
				if (range > 0.0 && range <= 0.9) {
					cout << "\n";
					taylor(terms, range);
				}
				else {
					cout << "The range of B must be between 0.0 - 0.9, please try again." << endl;
				}

			}
			else {
				cout << "The number of terms must be in the between 1 - 6, please try again." << endl;
			}

		}
		else if (choice == 2) {
			break;
		}
		else {
			cout << "Invalid input, please try again " << endl;
			break;
		}

	}

	return 0;
}