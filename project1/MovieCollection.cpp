/* MovieCollection.cpp
 * Ethan Clark
 * February 11, 2015
 * Begun by Joel Adams, for CS 112 at Calvin College
 * Project 1
 */

// Includes for the Movie Collection Class.
#include "MovieCollection.h"
#include <fstream>
using namespace std;

/* MovieCollection() constructs our collection using the data
 *   in a given source file.
 *
 * @param: fileName, a string.
 * Precondition: fileName contains the name of an input file
 *                containing the data of N Movies (N >= 1),
 *                separated by blank lines, ending with a newline.
 * Postcondition: myMovies.size() == N &&
 *                myMovies contains the Movies in fileName.
 */
MovieCollection::MovieCollection(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	Movie aMovie;
	while (true) {
		aMovie.readFrom(fin);
		if ( !fin ) break;
		string blankLine;
		getline(fin, blankLine);
		myMovies.push_back(aMovie);
	}
	fin.close();
}

/* searchByDirector() searches the collection for movies by a given director.
 *
 * @param: director, a string containing the director's name (or a part of it)
 * @return: a vector containing all movies in the collection
 *           for whom director is a substring of myDirector.
 */
vector<Movie> MovieCollection::searchByDirector(const string& directorName) const {
   vector<Movie> v;
   for (unsigned i = 0; i < myMovies.size(); i++) {
      if ( myMovies[i].getDirector().find(directorName) != string::npos ) {
         v.push_back( myMovies[i] );
      }
   }
   return v;
}

/* searchByYear() searches the collection for movies released in a given year.
 *
 * @param: year, an integer that is the year the movie was released
 * @return: a vector containing all movies in the collection which were the same
 * 			as the year which was searched.
 */
vector<Movie> MovieCollection::searchByYear(const int& Movieyear) const {
	vector<Movie> vec1;
	for (unsigned i = 0; i < myMovies.size(); i++) {
		if ( myMovies[i].getYear() == Movieyear ) {
			vec1.push_back( myMovies[i] );
		}
	}
	return vec1;
}

/* searchByTitlePhrase() searches the collection for movies by Title.
 *
 * @param: phrase, a string containing part of or all the title of a movie
 * @return: a vector containing all movies in the collection which had the phrase
 * 			in part of the movie's title
 */
vector<Movie> MovieCollection::searchByTitlePhrase(const string& phrase){
	vector<Movie> vec2;
	for (unsigned i = 0; i < myMovies.size(); i++) {
		if ( myMovies[i].getTitle().find(phrase) != string::npos ) {
			vec2.push_back( myMovies[i] );
		}
	}
	return vec2;
}

/* addMovie() adds a movie entry into the collection of movies.
 *
 * @param: newMovie, a Movie type that has title, year, and director attributes to it.
 * Precondition: myMovies contains N movies from the movie collection file
 * Postcondition: myMovies.size() = N + 1
 * 				  myMovies contains all the movies it originally contained, plus the new one added
 */
void MovieCollection::addMovie(const Movie& newMovie) {
	myMovies.insert(myMovies.begin(), newMovie);
}

/* removeMovie() removes a movie entry from the collection of movies.
 *
 * @param: aMovie, a Movie type that has title, year, and director attributes to it.
 * Precondition: myMovies contains N movies from the movie collection file
 * Postcondition: myMovies.size() = N - 1
 * 				  myMovies contains all the movies it originally contained, minus the one removed
 */
void MovieCollection::removeMovie(const Movie& aMovie) {
	for (unsigned i = 0; i < myMovies.size(); i++) {
		if ( myMovies[i].getTitle() == aMovie.getTitle() ) {
			if ( myMovies[i].getYear() == aMovie.getYear() ){
				if ( myMovies[i].getDirector() == aMovie.getDirector() ) {
					myMovies.erase(myMovies.begin()+i);
				}
			}
		}
	}
}

/* save() writes the current existing vector of Movies to a text file.
 *
 * Precondition: myMovies contains N movies, the original movies and then possibly
 * 				 movies added or removed by a user.
 * Postcondition: The text file contains all the movies that were added or removed by a user
 */
void MovieCollection::save() const{
	ofstream fout("PhilMovieCollection.txt");
	for (unsigned i = 0; i < myMovies.size(); i++) {
		myMovies[i].writeTo(fout);
		fout << '\n';
	}
	fout.close();
}
