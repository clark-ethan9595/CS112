/* Movie.h
 * Student Name: Ethan Clark
 * Date: February 10, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
#include <cassert>
#include <fstream>
using namespace std;

class Movie {
public:
	Movie();
	Movie(const string& title, int year, const string& director);
	string getTitle() const;
	int getYear() const;
	string getDirector() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	void operator==(const Movie& movie2) const;
private:
	string myTitle;
	int myYear;
	string myDirector;
};

#endif /* MOVIE_H_ */
