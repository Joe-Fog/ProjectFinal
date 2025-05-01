#include "Club.h"
#include "Exceptions.h"
#include <algorithm>
#include <iostream>

using namespace std;

//Default constructor
Club::Club() 
  : name(""), record(Record()), playerCount(0) { }

// Constructor w name and record
Club::Club(const string &name, const Record &record) 
  : name(name), record(record), playerCount(0) { }

//Display club name, record, and players
void Club::displayClub() const {
    cout << "Club: " << name << endl;
    record.displayRecord();
    for (int i = 0; i < playerCount; i++) {
        players[i].displayPlayer(); //shows all players
    }
    cout << endl;  
}
