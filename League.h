#ifndef LEAGUE_H
#define LEAGUE_H

#include "Club.h"
#include <algorithm>
using namespace std;

class League { //football league containing all clubs
private:
    string name; //name of league
    Club clubs[5]; //fixed to hold 5 clubs max
    int clubCount; // tracks previous line
public:
    League(); // Default constructor
    League(string name); 
    void addClub(Club club); //add club to league
    void displayLeague(); //displays league

    // ----------------------------------Final assignment----------------------------------//
    //  Sort clubs alphabetically by name (1)
    void sortClubsByName() {
       sort(clubs, clubs + clubCount);
       }

    //   Sort Player in clubs by goals scorrd (2)
    int getClubCount() const {
        return clubCount;
    }

    Club& getClub(int i) {
        return clubs[i];
    }
    const Club& getClub(int i) const {
        return clubs[i];
    }
    void saveFile(const string& filename) const;   // saving league details to a file

    // Read the entire league (clubs, records, players) from a file
    void loadFile(const string& filename);
};

#endif
