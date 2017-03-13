/* Movie.h
 * Student Name: Ethan Clark
 * Date: February 11, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Project1
 */

#ifndef MOVIE_H_
#define MOVIE_H_

// Includes for this Movie Class.
#include <string>
#include <cassert>
#include <fstream>
using namespace std;

// Class name and prototypes of the methods.
class Movie {
public:
	Movie();
	Movie(const string& title, int year, const string& director);
	string getTitle() const;
	int getYear() const;
	string getDirector() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	bool operator==(const Movie& movie2) const;

// Declaration of private variables for the Movie class.
private:
	string myTitle;
	int myYear;
	string myDirector;
};

#endif /* MOVIE_H_ */
