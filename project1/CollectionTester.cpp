/* CollectionTester.cpp defines the MovieCollection test-methods.
 * Student Name: Ethan Clark
 * Date: February 11, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Project1
 */

// Includes for this Movie Collection Tester class.
#include "CollectionTester.h"

// Method that runs the tests on the collection of movies file.
void CollectionTester::runTests() const {
   cout << "Testing MovieCollection Class..." << endl;
   testConstructor();
   testSearchByTitlePhrase();
   testSearchByYear();
   testAddandRemoveMethods();
   testSave();
   cout << "All tests passed!" << '\n' << endl;
}

// Method that tests the constructor of the movies in the movie collection.
void CollectionTester::testConstructor() const {
	cout << "- constructor..." << flush;
	MovieCollection mc("testCollection.txt");

    // case of 1 movie
    vector<Movie> v1 = mc.searchByDirector("Hand");
    assert( v1.size() == 1 );
    assert( v1[0].getTitle() == "Bambi" );
    cout << " 1 " << flush;

    // case of 2 movies
    vector<Movie> v2 = mc.searchByDirector("Spielberg");
    assert( v2.size() == 2 );
    assert( v2[0].getTitle() == "Jaws" );
    assert( v2[1].getTitle() == "Raiders of the Lost Ark" );
    cout << " 2 " << flush;

    // case of no movies
    vector<Movie> v3 = mc.searchByDirector("Hitchcock");
    assert( v3.size() == 0 );
    cout << " 3 " << flush;
	cout << " Passed!" << endl;
}

//Test the SearchByYear Method from the Movie Collection Class
void CollectionTester::testSearchByYear() const {

	cout << "- SearchByYear()..." << flush;
	MovieCollection mc("testCollection.txt");

	//Case of 2 movies
	vector<Movie> v1 = mc.searchByYear(1939);
	assert( v1.size() == 2 );
	assert( v1[0].getYear() == 1939 );
	assert( v1[1].getYear() == 1939 );
	cout << " 1 " << flush;

	//Case of 1 movie
	vector<Movie> v2 = mc.searchByYear(1981);
	assert( v2.size() == 1 );
	assert( v2[0].getYear() == 1981 );
	cout << " 2 " << flush;

	//Case of no movies
	vector<Movie> v3 = mc.searchByYear(1919);
	assert( v3.size() == 0 );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

//Method that tests the SearchByTitlePhrase() method of the movie collection class.
void CollectionTester::testSearchByTitlePhrase() const {

	cout << "- SearchbyTitlePhrase()... " << flush;
	MovieCollection mc("testCollection.txt");

	// case of 1 movie
	vector<Movie> v1 = mc.searchByTitlePhrase("Gone");
	assert( v1.size() == 1 );
	assert( v1[0].getTitle() == "Gone with the Wind");
	cout << " 1 " << flush;

	// case of 2 movies
	vector<Movie> v2 = mc.searchByTitlePhrase("the");
	assert( v2.size() == 2 );
	assert( v2[0].getTitle() == "Gone with the Wind");
	assert( v2[1].getTitle() == "Raiders of the Lost Ark");
	cout << " 2 " << flush;

	// case of 0 movies
	vector<Movie> v3 = mc.searchByTitlePhrase("Champion");
	assert( v3.size() == 0 );
	cout << " 3 " << flush;
	cout << " Passed!" << endl;
}

//Method that tests the addMovie and removeMovie methods from the Movie Collection class.
void CollectionTester::testAddandRemoveMethods() const {

	//Create a new Movie
	cout << "- AddandDeleteMovies()..." << flush;
	Movie m1("Step Brothers", 2008, "Adam McKay");

	//Create a MovieCollection and add the new Movie to the Collection
	MovieCollection mc1("testCollection.txt");
	mc1.addMovie(m1);

	//Test that the new Movie is in the MovieCollection
	vector<Movie> v1 = mc1.searchByTitlePhrase("Step Brothers");
	assert( v1.size() == 1 );
	assert( v1[0].getTitle() == "Step Brothers");
	assert( v1[0].getDirector() == "Adam McKay");
	assert( v1[0].getYear() == 2008);
	cout << " 1 " << flush;

	//Remove the new Movie from the MovieCollection and test that it was removed
	mc1.removeMovie(m1);
	vector<Movie> v2 = mc1.searchByTitlePhrase("Step Brothers");
	assert( v2.size() == 0 );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

//Method that tests the save() method of the Movie Collection class.
void CollectionTester::testSave() const {

	// Create a MovieCollection and two Movies
	cout << "- Save()..." << flush;
	MovieCollection mc1("PhilMovieCollection.txt");
	Movie m1("Harry Potter and the Sorcerer's Stone", 2001, "Chris Columbus");
	Movie m2("The Lord of the Rings: The Fellowship of the Ring", 2001, "Peter Jackson");

	//Test that the MovieCollection has no Movie titled "Harry Potter and the Sorcerer's Stone"
	vector<Movie> v1 = mc1.searchByTitlePhrase("Harry Potter and the Sorcerer's Stone");
	assert( v1.size() == 0 );

	//Add the Harry Potter Movie to the MovieCollection
	mc1.addMovie(m1);

	//Test that the MovieCollection has no Movie titled "The Lord of the Rings: The Fellowship of the Ring"
	vector<Movie> v3 = mc1.searchByTitlePhrase("The Lord of the Rings: The Fellowship of the Ring");
	assert( v3.size() == 0 );

	//Add the Lord of the Rings Movie to the MovieCollection
	mc1.addMovie(m2);

	//Save the current MovieCollection vector to the text file
	mc1.save();

	//Test that the Harry Potter Movie is now in the MovieCollection
	vector<Movie> v2 = mc1.searchByTitlePhrase("Harry Potter and the Sorcerer's Stone");
	assert( v2.size() == 1 );
	cout << " 1 " << flush;

	//Test that the Lord of the Rings Movie is now in the MovieCollection
	vector<Movie> v4 = mc1.searchByTitlePhrase("The Lord of the Rings: The Fellowship of the Ring");
	assert( v4.size() == 1 );
	cout << " 2 " << flush;

	mc1.removeMovie(m1);
	mc1.removeMovie(m2);

	mc1.save();

	//Test that the Harry Potter Movie and the Lord of the Rings Movie are gone from the file.
	MovieCollection mc2("PhilMovieCollection.txt");
	vector<Movie> vec1 = mc2.searchByTitlePhrase("Harry Potter and the Sorcerer's Stone");
	assert( vec1.size() == 0 );
	cout << " 3 " << flush;

	vector<Movie> vec2 = mc2.searchByTitlePhrase("The Lord of the Rings: The Fellowship of the Ring");
	assert( vec2.size() == 0 );
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}
