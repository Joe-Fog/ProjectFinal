#ifndef CLUB_H
#define CLUB_H

#include <string>	
#include <algorithm>
#include <iostream>
#include "Player.h"
#include "Record.h"
#include "Exceptions.h" // Include the exception header
using namespace std;

class Club {
private:
    string  name;
    Player  players[5];
    int playerCount;
    Record  record;

public:
    Club(); // Default constructor

    Club(const string &name, const Record &record);

    // add player to club if already in club it will throw an exception
    void addPlayer(const Player &player) {
        // findPlayer returns nullptr if not found
        if (findPlayer(player.getName()) != nullptr) {
            throw DuplicatePlayerException(player.getName());
        }
        players[playerCount++] = player;
    }

    void displayClub() const;

    // <<< sort(clubs,clubs+count) to alphabetize by name <---------------------------------------------------- (1)
    bool operator<(const Club &other) const {
        return name < other.name;
    }

    // Sort players by goals scored <-------------------------------------------------------------------------- (2)
    void sortPlayersByGoals() {
        sort(players, players + playerCount,
             [](const Player &a, const Player &b) {
                 return a.getGoals() > b.getGoals();  // descending
             }
        );
    }

    //search for player by name <------------------------------------------------------------------------------ (3)
    // This function returns a pointer to the player if found, otherwise returns nullptr

    Player* findPlayer(const string &searchName) {
        auto it = find_if(players, players + playerCount,
            [&](const Player &p) { // lambda function to compare players
                return p.getName() == searchName;  // requires Player::getName(), compares players name to the search term
            }
        );
        if (it == players + playerCount) //no match found return nullptr
            return nullptr;
        return it; // return pointer to the found player
    }

    // ------------ helpers for League::saveFile() ------------
    const  string&  getName()   const {
        return name;
    }
    int getPlayerCount()    const {
        return playerCount;
    }
    const Player&  getPlayer(int i) const {
        return players[i];
    }
    const Record&  getRecord()  const {
        return record;
    }

};

#endif
