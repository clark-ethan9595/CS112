/* Movie.cpp
 * Student Name: Ethan Clark
 * Date: February 11, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Project1
 */

// Includes for this class.
 #include "Movie.h"

// Default Constructor
Movie::Movie() {
	myTitle = "";
	myYear = 0;
	myDirector = "";
}

// Explicit Constructor to create instances of the Movie Class.
Movie::Movie(const string& title, int year, const string& director) {
	myTitle = title;
	myYear = year;
	myDirector = director;
}

// Method to return the title of the movie.
string Movie::getTitle() const {
	return myTitle;
}

// Method to return the year the movie was made.
int Movie::getYear() const {
	return myYear;
}

// Method to return the director of the movie.
string Movie::getDirector() const {
	return myDirector;
}

// Method to read in the title, year, and director of a movie from an outside file.
void Movie::readFrom(istream& in) {
	getline(in, myTitle);
	in >> myYear;
	string newLine; getline(in, newLine);
	getline(in, myDirector);
}

// Method to write the title, year and director of a movie to a file.
void Movie::writeTo(ostream& out) const {
	out << myTitle << '\n'
		<< myYear << '\n'
		<< myDirector << '\n';
}

/* operator==() compares two movies to see if they are the same or not.
 *
 * @param: movie2, a Movie type that has title, year, and director attributes to it
 * @return: bool, either returns true or false depending on if the two movies that were
 * 				  compared were the same or different
 */
bool Movie::operator==(const Movie& movie2) const{
	if ( myTitle == movie2.getTitle() ){
		if ( myYear == movie2.getYear() ) {
			if ( myDirector == movie2.getDirector() ) {
				return true;
			}
		}
	}
	return false;
}
