/* PlayListTester.h tests the PlayList class.
* Sam Hoogewind (sth6)
* Date: February 9, 2021
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

#ifndef PLAYLISTTESTER_
#define PLAYLISTTESTER_

class PlayListTester {
public:
    void runTests();
    void testConstructors();
    void testSearchByArtist();
    void testSearchByYear();
    void testSearchByTitlePhrase();
    void testAddAndDeleteSong();
    void testSave();
};

#endif /*PLAYLISTTESTER_*/
