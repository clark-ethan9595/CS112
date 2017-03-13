/* array.cpp defines "C style" array operations
 * Name: Ethan Clark
 * Date: February 22, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

//Includes for the array.cpp file
#include "array.h"

/*
 * initialize() initializes an array with size (a number) values.
 * @param: array of doubles, size of the array
 */
void initialize(double *a, int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}

/*
 * Print() outputs the elements of the array in the console.
 * @param: array of doubles, size of the array
 * Precondition: Array must be initialized with size values
 * Postcondition: Array's elements are output on the console.
 */
void print(double *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

/*
 * Average() returns the average of an array of doubles.
 * @param: array of doubles, size of the array
 * @return: double variable containing the average of the array's elements
 */
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
/*
 * Sum() returns the sum of the elements in an array of doubles.
 * @param: array of doubles, size of the array
 * @return: double variable containing the sum of the array's elements
 */
double sum(double *a, int size) {
	double val = 0;
	for (int i = 0; i < size; i++) {
		val = val + *(a+i);
	}
	return val;
}

/*
 * read() reads in values from a file and assigns them to a.
 * @param: input stream, array of doubles, size of the array
 * Precondition: An open input stream to a file, an initialized array
 * Postcondition: array a now contains the values from the file
 */
void read(istream& in, double *a,int size) {
	for ( int i = 0; i < size; i++ ) {
		in >> *a;
		a++;
	}
}

/*
 * fill() opens an input stream, stores the addresses of the values into a
 * @param: Filename (the name of a file), an array of doubles, size for the array
 * 				for the new elements
 * Precondition: Filename must be the name of a text file, array must be initialized
 * Postcondition: array a contains addresses of the values from the file
 */
void fill(const string& Filename, double *&a, int &numValues) {
	ifstream fin( Filename.c_str() );
	assert ( fin.is_open() );

	delete [] a;

	fin >> numValues;

	a = new double[numValues];

	for ( int i = 0; i < numValues; i++ ) {
		fin >> a[i];
	}

	fin.close();

}

/*
 * resize() changes the size of the original array to the new size.
 * @param: array of doubles, size of the old array, size of the new array
 * Precondition: array must be initialized
 * Postcondition: array either adds on the new elements from the existing elements
 * 					or it truncated the elements if the new size < the old size
 */
void resize(double *&a, int oldSize, int newSize) {
	if (newSize >= oldSize) {
		double* newArr = new double[newSize]();
		for ( int i = 0; i < oldSize; i++) {
			newArr[i] = a[i];
		}

		delete [] a;
		a = newArr;
	}

	if (oldSize > newSize) {
		double* newArr = new double[newSize];
		for ( int i = 0; i < newSize; i++) {
			newArr[i] = a[i];
		}

		delete [] a;
		a = newArr;
	}
}

/*
 * concat() combines two arrays into a third array containing the elements of the first
 * 			array first and then the elements of the second array.
 * @param: three arrays of doubles, sizes of all those arrays
 * Precondition: all three arrays initialized properly
 * Postcondition: array a3 contains both the elements from array a1 and array a2
 */
void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3) {
	size3 = size1 + size2;

	double* newArr = new double[size3];

	for ( int i = 0; i < size1; i++ ) {
		newArr[i] = *a1;
		a1++;
	}

	for ( int i = size1; i < size3; i++ ) {
		newArr[i] = *a2;
		a2++;
	}

	delete [] a3;
	a3 = newArr;
}
