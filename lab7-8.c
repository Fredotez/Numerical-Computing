/***************************************************************************************************************************************************************
Filename:				lab7-8.c
Version: 				1.0
Author:					Frederic Desjardins
Course Name/Number:		CST 8233 (Numerical Computing)
Assignment #:			lab 7-8
Assignment name:		Descriptive Statistics
Purpose:				

This program shows a menu to the user. The user will first be asked to input a certain number of data.
Options for the user are to calculate 

-Mean
-Mode
-Range
-Variance
-Standard Deveation 
****************************************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CRT_NO_WARNING

void sort(int num, float* data);
float mean(int num, float* data);
float median(int num, float* data);
float mode(int num, float* data);
float range(int num, float* data);
float variance(int num, float* data, float mean);
float stanDev(int num, float* data, float variance);


void sort(int num, float* data) {

	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

float mean(int num, float *data) {
	int i;
	float mean = 0;

	for (i = 0; i < num; i++) {
		mean += *(data + i);
	}

	mean = mean / num;

	return mean;
}

float median(int num, float* data) {
	float median = 0;
	int i;

	if (num % 2 == 0) {
		median = (data[(num - 1) / 2] + data[num / 2]) / 2.0;
	}
	else {
		median = data[num / 2];
	}

	return median;
}

float mode(int num, float* data) {
	int mode = 0;
	int highest = 0;
	int i, u;

	for (i = 0; i < num; i++) {
		int count = 0;

		for (u = 0; u < num; u++) {
			if (data[u] == data[i]) ++count;
		}

		if (count > highest) {
			highest = count;
			mode = data[i];
		}
	}

	if (highest <= 1) {
		return -1;
	}
	else {
		return mode;
	}
}

float range(int num, float* data) {
	float range;

	range = *(data + (num-1)) - *(data);

	return range;
}

float variance(int num, float* data, float mean) {
	float variance = 0;
	int i;

	for (i = 0; i < num; i++) {
		variance += pow(*(data + i) - mean, 2);
	}

	variance = variance / (num-1);
	return variance;
}

float stanDev(int num, float* data, float variance) {
	float sd = 0;

	sd = sqrt(variance);

	return sd;
}


int main() {

	int num;
	float* data;
	int i;
	float meanVal;
	float rangeVal; 
	float medianVal;
	float varianceVal;
	float standDevVal;
	float modeVal;
	printf("Enter the number of data points: ");
	scanf_s("%d", &num);

	data = (int*)malloc(sizeof(int) * num);

	for (i = 0; i < num; i++) {

		printf("Enter a number between 1 and 10:");
		scanf_s("%f", (data + i));
	}

	sort(num, data);

	meanVal = mean(num, data);
	medianVal = median(num, data);
	modeVal = mode(num, data);

	rangeVal = range(num, data);
	varianceVal = variance(num, data, mean(num, data));
	standDevVal = stanDev(num, data, variance(num, data, mean(num, data)));

	printf("\nMean=%0.1f\n", meanVal);
	printf("Median=%0.1f\n", medianVal);
	printf("Mode=%0.1f\n", modeVal);
	

	printf("Range=%0.1f\n", rangeVal);
	printf("Variance=%0.1f\n", varianceVal);
	printf("Standard deviation=%0.3f\n", standDevVal);

	printf("Data after standardization: \n");

	float standard;
	
	for (int i = 0; i < num; i++) {
		standard = ((data[i] - meanVal) / standDevVal);
		printf("%0.6f\n", standard);
	}

	return 0;
}
