#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"
#include <iostream>
#include <cstring> //(5) using dynamic memory allocation
using namespace std;

// shows football players individual stats
class Player : public Person { //inherits from Person
private:
    char* name; 
    int gamesPlayed; 
    int goals; 
    int assists; 
    double wages;
    static int playerCount; // Static variable to track total players

public:
    Player(); // Default constructor

    Player(const char* name, int games, int goals, int assists, double wages);

     // Copy constructor for deep copy. (3)
     Player(const Player &other);

    // Overloaded assignment operator for deep copy (4)
    Player& operator=(const Player &other);

    ~Player(); // Destructor to free dynamically allocated memory

    void displayPlayer() const; // Displays player details

    void display() const override; //Override display
    
    // Mutator set added to stop negative wages, goals, and assists
    void setGoals(int g);
    void setAssists(int a);
    void setWages(double w);

    int getGoals() const{ // Returns the number of goals <---------------------------------------------------- (2)
        return goals;
    }

    string getName() const{ // Returns namen as string <---------------------------------------------------- (3)
        return name;
    }

    // ---- for saving to file ----
    int  getGamesPlayed()        const { return gamesPlayed; }
    int  getAssists()            const { return assists; }
    double getWages()            const { return wages; }

    static int getPlayerCount(); // Returns the total number of players - static variable

     // Overloaded comparison operators to compare player's goals (1)
     bool operator==(const Player &other) const; //checks same number of goals
     bool operator!=(const Player &other) const; //checks different number of goals
     bool operator<(const Player &other) const; //checks fewer number of goals
     bool operator>(const Player &other) const; //checks more number of goals

      // Overloaded stream operators as friend functions (2)
    friend ostream &operator<<(ostream &os, const Player &player); // The friend keyword allows these functions to access private members of Player
    friend istream &operator>>(istream &is, Player &player);
};

#endif
