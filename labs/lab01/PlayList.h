/* PlayList.h declares class PlayList.
* Sam Hoogewind (sth6)
* Date: February 9, 2021
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>   // STL vector
#include <string>
using namespace std;

class PlayList {
public:
   PlayList(const string& fileName);
   unsigned getNumSongs() const;
   vector<Song> searchByArtist(const string& artist) const;
   vector<Song> searchByYear(unsigned year) const;
   vector<Song> searchByTitlePhrase(const string& phrase);
   void addSong(const Song& newSong);
   void removeSong(const Song& aSong);
   void save() const;
private:
   vector<Song> mySongs;
};

#endif /*PLAYLIST_H_*/
