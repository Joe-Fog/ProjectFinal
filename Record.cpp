#include "Record.h"
#include <iostream>

using namespace std;

// Default constructor
Record::Record() : matchesPlayed(0), trophiesWon(0) {}

Record::Record(int played, int trophies) 
    : matchesPlayed(played), trophiesWon(trophies) {}

void Record::displayRecord() const {
    int matchesLeft = TOTAL_MATCHES - matchesPlayed; // Calculate matches left. const used for matches played
    cout << "Matches Played: " << matchesPlayed 
         << " | Trophies Won: " << trophiesWon 
         << " | Matches Left: " << matchesLeft << endl;
}
