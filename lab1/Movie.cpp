/* Movie.cpp
 * Student Name: Ethan Clark
 * Date: February 10, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

 #include "Movie.h"

Movie::Movie() {
	myTitle = "";
	myYear = 0;
	myDirector = "";
}

Movie::Movie(const string& title, int year, const string& director) {
	myTitle = title;
	myYear = year;
	myDirector = director;
}

string Movie::getTitle() const {
	return myTitle;
}

int Movie::getYear() const {
	return myYear;
}

string Movie::getDirector() const {
	return myDirector;
}

void Movie::readFrom(istream& in) {
	getline(in, myTitle);
	in >> myYear;
	string newLine; getline(in, newLine);
	getline(in, myDirector);
}

void Movie::writeTo(ostream& out) const {
	out << myTitle << '\n'
		<< myYear << '\n'
		<< myDirector << '\n';
}
