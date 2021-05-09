/***************************************************************************************************************************************************************
Filename:				lab6.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 6
Assignment name:		Maclurin series Expansion
Purpose:				

Write a C\C++ program to compute the function 𝑓(𝑥) = cos 𝑥 using the series shown 
above. Your program should print the final value of 𝑓(𝑥) = cos 𝑥 you also needs to get 
the true value of 𝑓(𝑥) = cos 𝑥 using the built-in cos 𝑥 function in C\C++.

****************************************************************************************************************************************************************/



#include <iostream>
#include <iomanip> 
#include <cmath>

#define M_PI 3.14159265358979323846

/*
*Assignment: Lab 5
*Name: Frederic Desjardins

Topic: Maclurin series Expansion
*Purpose:

Objective: Write a C\C++ program to compute the function 𝑓(𝑥) = cos 𝑥 using the series shown 
above. Your program should print the final value of 𝑓(𝑥) = cos 𝑥 you also needs to get 
the true value of 𝑓(𝑥) = cos 𝑥 using the built-in cos 𝑥 function in C\C++.

*/

using namespace std;

void taylor(double absolute) {

    double x = M_PI / 3;
    double exactValue = cos(x);
    double absoluteError = 0;
    double relativeError = 0;
    
    cout << "N.terms" << "\t" << "Exact value" << "\t" << "Aproximate value" << "\t" << "Absolute error" << "\t" << "%trelative error" << endl;
       
    double maclaurin2 = 1 - pow(x, 2) / 2;        
      
    double maclaurin3 = 1 - pow(x, 2) / 2 + pow(x, 4) / 24;       
      
    double maclaurin4 = 1 - pow(x, 2) / 2 + pow(x, 4) / 24 - pow(x,6) / 720;        
       
    double maclaurin5 = 1 - pow(x, 2) / 2 + pow(x, 4) / 24 - pow(x, 6) / 720 + pow(x,8) / 40320;

    double possibleMaclaurin[4] = { maclaurin2, maclaurin3, maclaurin4, maclaurin5 };

    int i = 0;

    while (1) {

        absoluteError = abs(exactValue - possibleMaclaurin[i]);
        relativeError = 100* abs(absoluteError / exactValue);

        cout.precision(6);
        cout << fixed << i << " \t" << exactValue << " \t" << possibleMaclaurin[i] << " \t" << absoluteError << " \t" << relativeError << endl;

        if (absoluteError < absolute) {
            break;
        }
        else {
            i++;
        }

    }
    
}

//trunk error = trunk / exact;
//relative error = absolute error / valeur exact

int main() {

    double absolute;
    cout << "Enter your error bound: " << endl;
    cin >> absolute;
    taylor(absolute);
    return 0;
}