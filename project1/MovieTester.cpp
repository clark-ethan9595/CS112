/* MovieTester.cpp
 * Student Name: Ethan Clark
 * Date: February 11, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Project1
 */

// Includes for the movie tester class.
#include "MovieTester.h"

// Method that runs the different tests on the movies.
void MovieTester::runTests() const {
   cout << "Testing Movie class..." << endl;
   testDefaultConstructor();
   testExplicitConstructor();
   testReadFrom();
   testWriteTo();
   testComparison();
   cout << "All tests passed!" << '\n' << endl;
}

// Method to test the default constructor of the Movie Class.
void MovieTester::testDefaultConstructor() const {
    cout << "- Default Constructor ... " << flush;
    Movie m;
    assert( m.getTitle() == "" );
    assert( m.getYear() == 0 );
    assert( m.getDirector() == "" );
    cout << " Passed!" << endl;
}

// Method to test the explicit constructor of the Movie Class.
void MovieTester::testExplicitConstructor() const {
    cout << "- Explicit Constructor... " << flush;
    Movie m("Bambi", 1942, "David Hand");
    assert( m.getTitle() == "Bambi" );
    assert( m.getYear() == 1942 );
    assert( m.getDirector() == "David Hand" );
    cout << "Passed!" << endl;
}

// Method to test the reading from a file for movies.
void MovieTester::testReadFrom() const {
	cout << "- readFrom()... " << flush;
	ifstream fin("movieTest.txt");
	assert( fin.is_open() );
	Movie m;
	m.readFrom(fin);
	assert( m.getTitle() == "Gone with the Wind" );
	assert( m.getYear() == 1939 );
	assert( m.getDirector() == "Victor Fleming" );
	string blankLine;
	getline(fin, blankLine);
	m.readFrom(fin);
	assert( m.getTitle() == "Star Wars" );
	assert( m.getYear() == 1977 );
	assert( m.getDirector() == "George Lucas" );
	cout << "Passed!" << endl;
}

// Method to test the writing to a file for movies.
void MovieTester::testWriteTo() const {

   cout << "- writeTo()... " << flush;

   // declare a Movie with known values
   Movie m1("Raiders of the Lost Ark", 1981, "Steven Spielberg");

   // write it to a file
   ofstream fout("writeTo.txt");
   m1.writeTo(fout);
   fout.close();

   // now open the same file for reading
   ifstream fin("writeTo.txt");
   assert( fin.is_open() );

   // now read the Movie back from the file
   Movie m2;
   m2.readFrom(fin);

   // and check that we got the same values we wrote
   assert( m2.getTitle() == "Raiders of the Lost Ark" );
   assert( m2.getYear() == 1981 );
   assert( m2.getDirector() == "Steven Spielberg" );
   fin.close();
   cout << " 1 " << flush;

   // two movies
   Movie m3("Blade Runner", 1982, "Ridley Scott");
   fout.open("writeTo.txt");
   m1.writeTo(fout);                          // write 1st movie
   fout << "\n";                              // write a blank line
   m3.writeTo(fout);                          // write 2nd movie
   fout.close();
   fin.open("writeTo.txt");
   Movie m4, m5;
   m4.readFrom(fin);                          // read 1st movie
   string blankline; getline(fin, blankline); // eat the blank line
   m5.readFrom(fin);                          // read 2nd movie
   fin.close();
   assert( m4.getTitle() == "Raiders of the Lost Ark" );
   assert( m4.getYear() == 1981 );
   assert( m4.getDirector() == "Steven Spielberg" );
   assert( m5.getTitle() == "Blade Runner" );
   assert( m5.getYear() == 1982 );
   assert( m5.getDirector() == "Ridley Scott" );
   cout << " 2 " << flush;

   cout << "Passed!" << endl;
}

// Method that tests if two movies are the same.
void MovieTester::testComparison() const {

	cout << "- Comparison()... " << flush;

	// Declare two movies with known values.
	Movie m1("Raiders of the Lost Ark", 1981, "Steven Spielberg");
	Movie m2("Blade Runner", 1982, "Ridley Scott");

	// Assert that the movies are not the same.
	assert( m1.operator ==(m2) == false );
	cout << " 1 " << flush;

	// Create another movie, same as m1.
	Movie m3("Raiders of the Lost Ark", 1981, "Steven Spielberg");

	// Assert that movies m1 and m3 are the same.
	assert( m1.operator ==(m3) == true );
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}
