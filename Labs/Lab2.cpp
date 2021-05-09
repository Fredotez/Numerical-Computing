/***************************************************************************************************************************************************************
Filename:				lab2.cpp
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 6
Assignment name:		Number Systems
Purpose:				

Write a C\C++ program to convert from decimal to binary and from binary to 
decimal. 

****************************************************************************************************************************************************************/

#include <iostream>
#include<string>

using namespace std;

string decFracToBinary(double num) {

    string binary = "";

    // Get integer part of the number 
    int integer = num;

    // Get the fractional part of the number 
    double fractional = num - integer;
	
    while (integer)
    {
        int remainder = integer % 2;
        binary.push_back(remainder + '0');
        integer /= 2;
    }

    // Reverse string
    reverse(binary.begin(), binary.end());

    // Add period to binary 

    if (fractional != 0)
     binary.push_back('.');

    // Conversion of fractional part to binary
    while (fractional != 0)
    {
      
        fractional *= 2;
        int fractional_bit = fractional;

        if (fractional_bit == 1)
        {
            fractional -= fractional_bit;
            binary.push_back(1 + '0');
        }
        else
            binary.push_back(0 + '0');
    }
    
    return binary;
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    //Setting base exponent 
    int base = 1;

    //Temp to hold value of num
    int temp = num;

    while (temp) {

        //target last digit
        int last_digit = temp % 10;
        temp = temp / 10;

        //Mulitply last digit by base
        dec_value += last_digit * base;

        //update the base
        base = base * 2;
    }

    return dec_value;
}



double binaryFractionToDecimal(string binary, int len)
{
    // Get position of point 
    size_t point = binary.find('.');

    // if no point, update
    if (point == string::npos)
        point = len;

    double leftOfComma = 0;
    double rightOfComma = 0;
    double exp = 1;

    // Convert integer part to decimal
    for (int i = point - 1; i >= 0; --i)
    {
        
        
            leftOfComma += (binary[i] - '0') * exp;
            exp *= 2;
        
    }

    exp = 2;
    for (int i = point + 1; i < len; ++i)
    {
        
            rightOfComma += (binary[i] - '0') / exp;
            exp *= 2.0;
    }

    // Add both integral and fractional part 
    return leftOfComma + rightOfComma;
}


int main() {

    
    double decimalNum;
    string binaryNum;
    

    cout << "Enter a decimal number: \n";
    cin >> decimalNum;
    cout << decimalNum << " decimal is: " << decFracToBinary(decimalNum) << "\n";

    cout << "Enter a binary number: \n";
    cin >> binaryNum;
    cout << binaryNum << " binary is: " << binaryFractionToDecimal(binaryNum, binaryNum.length());

    return 0;

}