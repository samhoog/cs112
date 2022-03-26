/* PlayListTester.cpp defines the PlayList test-methods.
* Sam Hoogewind (sth6)
* Date: February 9,2021
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#include "PlayListTester.h"
#include "PlayList.h"
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

void PlayListTester::runTests() {
   cout << "\nTesting class PlayList..." << endl;
   testConstructors();
   testSearchByArtist();
   testSearchByYear();
   testSearchByTitlePhrase();
   testAddAndDeleteSong();
   testSave();
   cout << "All tests passed!" << endl;
}

void PlayListTester::testConstructors() {
   cout << "- constructors..." << flush;
   PlayList pList("testSongs.txt");
   assert( pList.getNumSongs() == 4 );
   cout << " 0 " << flush;

   cout << " Passed!" << endl;
}

void PlayListTester::testSearchByArtist() {
   cout << "- searchByArtist()... " << flush;
   // load a playlist with test songs
   PlayList pList("testSongs.txt");

   // empty case (0 artists)
   vector<Song> searchResult = pList.searchByArtist("Cream");
   assert( searchResult.size() == 0 );
   cout << " 0 " << flush;

   // case of 1 artist
   searchResult = pList.searchByArtist("Baez");
   assert( searchResult.size() == 1 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   cout << " 1 " << flush;

   // case of 2 artists
   searchResult = pList.searchByArtist("Beatles");
   assert( searchResult.size() == 2 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   assert( searchResult[1].getTitle() == "Penny Lane" );
   cout << " 2 " << flush;

   cout << " Passed!" << endl;
}

void PlayListTester::testSearchByYear() {
   cout << "- searchByYear()... " << flush;
   // load a playlist with test songs
   PlayList pList("testSongs.txt");

   // empty case (0 songs)
   vector<Song> searchResult = pList.searchByYear(2015);
   assert( searchResult.size() == 0);

   // case of 1 song
   searchResult = pList.searchByYear(2012);
   assert( searchResult.size() == 1);
   assert( searchResult[0].getTitle() == "Call Me Maybe" );
   cout << " 1 " << flush;

   // case of 2 songs
   searchResult = pList.searchByYear(1967);
   assert( searchResult.size() == 2 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   assert( searchResult[1].getTitle() == "Penny Lane" );
   cout << " 2 " << flush;

   cout << " Passed!" << endl;

}

void PlayListTester::testSearchByTitlePhrase() {
   cout << "- searchByTitlePhrase()... " << flush;
   // load a playlist with test songs
   PlayList pList("testSongs.txt");

   // empty case (0 titles)
   vector<Song> searchResult = pList.searchByTitlePhrase("Cream");
   assert( searchResult.size() == 0 );
   cout << " 0 " << flush;

   // case of 1 title
   searchResult = pList.searchByTitlePhrase("Maybe");
   assert( searchResult.size() == 1 );
   assert( searchResult[0].getTitle() == "Call Me Maybe" );
   cout << " 1 " << flush;

   // case of 2 titles
   searchResult = pList.searchByTitlePhrase("Let");
   assert( searchResult.size() == 2 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   assert( searchResult[1].getTitle() == "Let It Be" );
   cout << " 2 " << flush;

   cout << " Passed!" << endl;

}

void PlayListTester::testAddAndDeleteSong() {
   cout << "- addSong()... " << flush;
   // load a playlist with test songs
   PlayList pList("testSongs.txt");

   // create 1 new song
   Song newSong("Thriller", "Michael Jackson", 1982);
   pList.addSong(newSong);
   assert( pList.getNumSongs() == 5 );
   cout << " 1 " << flush;

   // create 2 new songs
   Song newSong2("Don't Stop Believin'", "Journey", 1981);
   pList.addSong(newSong2);

   Song newSong3("Bad", "Michael Jackson", 1987);
   pList.addSong(newSong3);
   assert( pList.getNumSongs() == 7 );
   cout << " 2 " << flush;

   // remove 1 song
   cout << "- removeSong()... " << flush;
   Song song1("Thriller", "Michael Jackson", 1982);
   pList.removeSong(song1);
   assert( pList.getNumSongs() == 6);
   cout << " 1 " << flush;

   // remove 2 songs
   Song song2("Don't Stop Believin'", "Journey", 1981);
   pList.removeSong(song2);

   Song song3("Bad", "Michael Jackson", 1987);
   pList.removeSong(song3);
   assert( pList.getNumSongs() == 4 );
   cout << " 2 " << flush;

   cout << " Passed!" << endl;

}

void PlayListTester::testSave() {
   cout << "- save()... " << flush;

   // declare three songs
   PlayList pList2("testPlaylist.txt");

   // write the playlist
   pList2.save();

   // use readFrom() to see if writeTo() worked
   ifstream fin("PlaylistOutput.txt");
   assert( fin.is_open() );
   Song s4, s5, s6;
   string separator;

   // read and check the first song
   s4.readFrom(fin);
   getline(fin, separator);
   assert( s4.getTitle() == "Badge" );
   assert( s4.getArtist() == "Cream" );
   assert( s4.getYear() == 1969 );
   cout << " 0 " << flush;

   // read and check the second song
   s5.readFrom(fin);
   getline(fin, separator);
   assert( s5.getTitle() == "Godzilla" );
   assert( s5.getArtist() == "Blue Oyster Cult" );
   assert( s5.getYear() == 1977 );
   cout << " 1 " << flush;

   // read and check the third song
   s6.readFrom(fin);
   getline(fin, separator);
   assert( s6.getTitle() == "Behind Blue Eyes" );
   assert( s6.getArtist() == "The Who" );
   assert( s6.getYear() == 1971 );
   cout << " 2 " << flush;

   fin.close();
   cout << " Passed!" << endl;

}
