/* Application.cpp defines the Application test-methods.
* Sam Hoogewind (sth6)
* Date: February 14,2021
*/

#include "Application.h"
#include "PlayList.h"
#include <iostream>
using namespace std;

PlayList pList("testSongs.txt");
Application::Application() {
	cout << "Welcome to the PlayList Manager!"
			"\n\nPlease Enter:\n   1 - to search the playlist for songs by a given artist\n"
			"   2 - to search the playlist for songs from a given year\n"
			"   3 - to search the playlist for songs with a given phrase\n"
			"   4 - to add a new song to the playlist\n"
			"   5 - to remove a song from the playlist\n"
			"   0 - to quit\n" << flush;
	int input;
	cin >> input;

	if (input == 1) {
		searchArtist();

	} else if (input == 2) {
		searchYear();

	} else if (input == 3) {
		searchTitle();

	} else if (input == 4) {
		addSong();

	} else if (input == 5) {
		removeSong();

	} else if (input == 0) {
		void exit (int status);

	} else {
		cout << "That is not a valid command." << flush;
	}
}

void Application::searchArtist() {
	cout << "Please enter the Artist:\n" << flush;
	string artist;
	cin >> artist;
	vector<Song> result = pList.searchByArtist(artist);
	if (result.size() == 0) {
	   cout << "No songs found by " << artist << "." << endl;
	} else {
	   for (unsigned i = 0; i < result.size(); ++i) {
	      cout << "Song Title: " << result[i].getTitle() << endl;
		  cout << "Song Artist: " << result[i].getArtist() << endl;
		  cout << "Song Year: " << result[i].getYear() << endl;
	   }
	}
	Application();
}

void Application::searchYear() {
	cout << "Please enter the year:\n" << flush;
	int year;
	cin >> year;
	vector<Song> result = pList.searchByYear(year);
	if (result.size() == 0) {
		cout << "No songs found in " << year << "." << endl;
	} else {
		for (unsigned i = 0; i < result.size(); ++i) {
			cout << "Song Title: " << result[i].getTitle() << endl;
			cout << "Song Artist: " << result[i].getArtist() << endl;
			cout << "Song Year: " << result[i].getYear() << endl;
		}
	}
	Application();
}

void Application::searchTitle() {
	cout << "Please enter the phrase:\n" << flush;
	string phrase;
	cin >> phrase;
	vector<Song> result = pList.searchByTitlePhrase(phrase);
	if (result.size() == 0) {
		cout << "No songs found with the phrase" << phrase << "." << endl;
		Application();
	} else {
	     for (unsigned i = 0; i < result.size(); ++i) {
		    cout << "Song Title: " << result[i].getTitle() << endl;
		    cout << "Song Artist: " << result[i].getArtist() << endl;
		    cout << "Song Year: " << result[i].getYear() << endl;
		    Application();
	     }
	}
}

void Application::addSong() {
	cout << "Please enter the song title:\n" << flush;
	string userTitle;
	cin >> userTitle;

	cout << "Please enter the song artist:\n" << flush;
	string userArtist;
	cin >> userArtist;

	cout << "Please enter the song year:\n" << flush;
	int userYear;
	cin >> userYear;

	Song newSong(userTitle, userArtist, userYear);
	pList.addSong(newSong);
	cout << "Song Added!\n" << flush;
	Application();

}

void Application::removeSong() {
	cout << "Please enter the song title:\n" << flush;
	string userTitle;
	cin >> userTitle;

	cout << "Please enter the song artist:\n" << flush;
	string userArtist;
	cin >> userArtist;

	cout << "Please enter the song year:\n" << flush;
	int userYear;
	cin >> userYear;

	Song newSong(userTitle, userArtist, userYear);
	pList.removeSong(newSong);
	cout << "Song Removed!\n" << flush;
	Application();

}

