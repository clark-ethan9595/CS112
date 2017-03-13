/* array.h declares "C style" array operations.
 * Name: Ethan Clark
 * Date: February 22, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
//All includes for the array files.
#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;

//Declaring the prototypes for all the array methods.
void initialize(double *a, int size);

void print(double *a, int size);

double average(double *a, int size);

double sum(double *a, int size);

void read(istream& in, double *a,int size);

void fill(const string& Filename, double *&a, int &numValues);

void resize(double *&a, int oldSize, int newSize);

void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3);
