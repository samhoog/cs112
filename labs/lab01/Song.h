/* Song.h declares a class for storing song information.
* Sam Hoogewind (sth6)
* Date: February 9, 2021
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#define SONG_H

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Song {
public:
	Song();
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;

	Song(const string& title, const string& artist, unsigned year);

	void readFrom(istream& in);

	void writeTo(ostream& out) const;
private:
	string   myTitle;
	string   myArtist;
	unsigned myYear;
};

