/* MovieCollection.h
 * Ethan Clark
 * February 11, 2015
 * Project1
 */

#ifndef MOVIECOLLECTION_H_
#define MOVIECOLLECTION_H_

// Includes for the Movie Collection Class.
#include <string>
#include "Movie.h"
#include <vector>
#include <cassert>
using namespace std;

// Creation of the Movie Collection Class and its prototypes.
class MovieCollection {
public:
   MovieCollection(const string& fileName);
   vector<Movie> searchByDirector(const string& directorName) const;
   vector<Movie> searchByYear(const int& Movieyear) const;
   vector<Movie> searchByTitlePhrase(const string& phrase);
   void addMovie(const Movie& newMovie);
   void removeMovie(const Movie& aMovie);
   void save() const;

// Creation of variables for the Movie Collection Class.
private:
   vector<Movie> myMovies;
};

#endif /*MOVIECOLLECTION_H_*/
