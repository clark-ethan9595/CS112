/* array.cpp defines "C style" array operations
 * Name: Ethan Clark
 * Date: February 17, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"

void initialize(double *a, int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
 
void print(double *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, int size) {
	double val = 0;
	for (int i = 0; i < size; i++) {
		val = val + *a;
		a++;
	}
	double average;
	average = val / size;
	return average;
}
