/* PlayList.cpp defines the PlayList methods.
* Sam Hoogewind (sth6)
* Date: February 9, 2021
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#include "PlayList.h"
#include <fstream>      // ifstream
#include <cassert>      // assert()
#include <iostream>
using namespace std;

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
PlayList::PlayList(const string& fileName) {
	// open a stream to the playlist file
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	// read each song and append it to mySongs
	Song s;
	string separator;
	while (true) {
	    s.readFrom(fin);
	    if ( !fin ) { break; }
	    getline(fin, separator);
	    mySongs.push_back(s);
	}

	// close the stream
	fin.close();
}

/* Retrieve length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

/* Search by artist
* @param: artist, a string.
* Return: a vector containing all the Songs in mySongs by artist.
*/
vector<Song> PlayList::searchByArtist(const string& artist) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); ++i) {
      if ( mySongs[i].getArtist().find(artist) != string::npos ) {
         v.push_back( mySongs[i] );
      }
   }

   return v;
}

/* Search by year
* @param: year, an integer.
* Return: a vector containing all the Songs in mySongs by year.
*/
vector<Song> PlayList::searchByYear(unsigned year) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); ++i) {
	  if ( mySongs[i].getYear() == year ) {
	     v.push_back( mySongs[i] );
	  }
   }

	 return v;
}

/* Search by title phrase
* @param: title phrase, a string.
* Return: a vector containing all the Songs in mySongs by title phrase.
*/
vector<Song> PlayList::searchByTitlePhrase(const string& phrase) {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); ++i) {
      if ( mySongs[i].getTitle().find(phrase) != string::npos ) {
         v.push_back( mySongs[i] );
      }
   }

   return v;
}

/* Add a new song to the playlist
* @param: song, a Song object
*/
void PlayList::addSong(const Song& newSong) {
	mySongs.push_back(newSong);
}

/* Remove a song from the playlist
* @param: song, a Song object
*/
void PlayList::removeSong(const Song& aSong) {

   for (unsigned i = 0; i < mySongs.size(); ++i) {
	   if (mySongs[i].getTitle() == aSong.getTitle()) {
		   if (mySongs[i].getArtist() == aSong.getArtist()) {
			   mySongs.erase(mySongs.begin()+(i));
		   }
	   }
   }

}

void PlayList::save() const {
	ofstream fout("PlaylistOutput.txt");
	for (unsigned i = 0; i < mySongs.size(); ++i) {
	   mySongs[i].writeTo(fout);
	   fout << "---\n";
	}
	fout.close();

}
