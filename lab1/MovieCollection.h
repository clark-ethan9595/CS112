/* MovieCollection.h
 * Ethan Clark
 * February 10, 2015
 * Lab1
 */

#ifndef MOVIECOLLECTION_H_
#define MOVIECOLLECTION_H_

#include <string>
#include "Movie.h"
#include <vector>
#include <cassert>
using namespace std;

class MovieCollection {
public:
   MovieCollection(const string& fileName);
   vector<Movie> searchByDirector(const string& directorName) const;
private:
   vector<Movie> myMovies;
};

#endif /*MOVIECOLLECTION_H_*/
