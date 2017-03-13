/* tester.cpp tests the classes in our project.
 * Ethan Clark
 * February 11, 2015
 * Project1
 */

// Includes the tester classes that test the Movie Class and Movie Collection Class.
#include "MovieTester.h"
#include "CollectionTester.h"
#include "Movie.h"
#include "MovieCollection.h"
#include <iostream>
using namespace std;

MovieCollection mc1("PhilMovieCollection.txt");

//Function that runs if the user chooses to search by TitlePhrase.
void moviePhraseTitle() {
	cout << "  Enter a phrase you would like to search the titles for: ";
	string entry;
	cin.ignore();
	getline(cin, entry);
	cout << '\n';

	vector<Movie> vec = mc1.searchByTitlePhrase(entry);
	for (unsigned i = 0; i < vec.size(); i++) {
		cout << vec[i].getTitle() << " : " << vec[i].getYear() << " : " << vec[i].getDirector() << '\n';
	}
	if ( vec.size() > 0 ) {
			cout << '\n';
	}
	if ( vec.size() == 0 ) {
		cout << "  There are no movies with that phrase in the title." << '\n' << endl;
	}
}

//Function that runs if the user chooses to search by year.
void movieYearSearch() {
	cout << "  Enter a year to see the movies released in that year: ";
	int entry;
	cin >> entry;
	cout << '\n';

	vector<Movie> vec = mc1.searchByYear(entry);
	for (unsigned i = 0; i < vec.size(); i++) {
		cout << vec[i].getTitle() << " : " << vec[i].getYear() << " : " << vec[i].getDirector() << '\n';
	}
	if ( vec.size() > 0 ) {
		cout << '\n';
	}
	if ( vec.size() == 0 ) {
		cout << "  There are no movies released in that year." << '\n' << endl;
	}
}

//Function that runs if the user chooses to search by director
void movieDirectorSearch() {
	cout << "  Enter a director's name to see their directed movies: ";
	string entry;
	cin.ignore();
	getline(cin, entry);
	cout << '\n';

	vector<Movie> vec = mc1.searchByDirector(entry);
	for (unsigned i = 0; i < vec.size(); i++) {
		cout << vec[i].getTitle() << " : " << vec[i].getYear() << " : " << vec[i].getDirector() << '\n';
	}
	if ( vec.size() > 0 ) {
			cout << '\n';
	}
	if ( vec.size() == 0 ) {
		cout << "  There are no movies with that director." << '\n' << endl;
	}
}

//Function that runs if the user chooses to add a movie to the collection.
void addMovietoCollection() {
	string title, director;
	int year;

	cout << "  Enter the title of the new movie: ";
	cin.ignore();
	getline(cin, title);

	cout << "  Enter the year the new movie was published: ";
	cin >> year;

	cout << "  Enter the director the of new movie: ";
	cin.ignore();
	getline(cin, director);
	cout << '\n';

	Movie m1(title, year, director);
	mc1.addMovie(m1);

	cout << "  The movie has been added to the collection!" << endl;
	cout << "  Make sure to save the current Movie Collection before exiting!" << '\n' << endl;
}

//Function that runs if the user chooses to remove a movie from the collection.
void removeMoviefromCollection() {
	string title, director;
	int year;

	cout << "  Enter the title of the new movie: ";
	cin.ignore();
	getline(cin, title);

	cout << "  Enter the year the new movie was published: ";
	cin >> year;

	cout << "  Enter the director the of new movie: ";
	cin.ignore();
	getline(cin, director);
	cout << '\n';

	Movie m1(title, year, director);
	mc1.removeMovie(m1);

	cout << "  The movie has been removed to the collection!" << endl;
	cout << "  Make sure to save the current Movie Collection before exiting!" << '\n' << endl;
}

//Function that runs if the user chooses to save the current movie collection to the file.
void saveCurrentMovies() {
	mc1.save();

	cout << "  The Movie Collection has been saved!" << '\n' << endl;
}

//Function to create an interface for the user to perform actions on Phil's Movie Collection.
void interfaceMethod() {

	// Forever loop to continue asking the user to perform actions until the user quits.
	while (true) {
		cout << "Welcome to Phil's Movie Collection Manager!" << '\n' << endl;
		cout << "Please enter:" << endl;
		cout << "  A - to search the collection for movies by phrase in the title" << endl;
		cout << "  B - to search the collection for movies released in a given year" << endl;
		cout << "  C - to search the collection for movies by a given director" << endl;
		cout << "  D - to add a movie to the movie collection" << endl;
		cout << "  E - to remove a movie from the movie collection" << endl;
		cout << "  S - to save the current movie collection to a file" << endl;
		cout << "  Q - to exit the program" << endl;
		cout << "  Type entry here: ";
		string userentry;
		cin >> userentry;

		//Determine which option the user selects
		if ( userentry == "A" or userentry == "a" ) {
			moviePhraseTitle();
		}
		if ( userentry == "B" or userentry == "b" ) {
			movieYearSearch();
		}
		if ( userentry == "C" or userentry == "c" ) {
			movieDirectorSearch();
		}
		if ( userentry == "D" or userentry == "d" ) {
			addMovietoCollection();
		}
		if ( userentry == "E" or userentry == "e" ) {
			removeMoviefromCollection();
		}
		if ( userentry == "S" or userentry == "s" ) {
			saveCurrentMovies();
		}
		if ( userentry == "Q" or userentry == "q" ) {
			break;
		}
	}
}

// Main method that runs the testing programs and the user interface program.
int main() {
	cout << "Would you like to run tests or use the interface movie manager?" << endl;
	cout << "O for running tests and 1 for movie manager: ";
	int user_entry;
	cin >> user_entry;
	cout << '\n';

	if ( user_entry == 0 ) {
	    MovieTester mt;
	    mt.runTests();
	    CollectionTester ct;
	    ct.runTests();
	}
	if ( user_entry == 1 ) {
		interfaceMethod();
	}
}
