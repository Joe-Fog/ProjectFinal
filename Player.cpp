#include "Player.h"
#include <iostream>

using namespace std;

//Static Variable
int Player::playerCount = 0; 

// Default constructor initializing an empty player
Player::Player() : name(""), gamesPlayed(0), goals(0), assists(0), wages(0) {
    name = new char[1];     // <-- (5)
    name[0] = '\0';         // <-- (5)
    playerCount++; // Increment player count when a new player is created
}

// Constructor initializing player details
Player::Player(const char* name, int games, int goals, int assists, double wages)
    : gamesPlayed(games), goals(0), assists(0), wages(0) {
    this->name = new char[strlen(name) + 1];  //Create space in memory to store the player's name (5)
    strcpy(this->name, name);               //string copy (5) copies the name to the allocated space (5)
    setGoals(goals);
    setAssists(assists);
    setWages(wages);
    playerCount++;
} //goes up a player when added

//------------------------------------------------------------------------//

// Copy constructor (deep copy). (3)
// This constructor is used to create a new Player object as a copy of an existing one.

Player::Player(const Player &other)
    : gamesPlayed(other.gamesPlayed), 
      goals(other.goals), 
      assists(other.assists), 
      wages(other.wages) {
        name = new char[strlen(other.name) + 1]; // Create space in memory to store the player's name (5)
        strcpy(name, other.name);                //string copy (5) copies the name to the allocated space (5)
    
    playerCount++;
}

//------------------------------------------------------------------------//
// Overloaded assignment operator for deep copy (4)
Player& Player::operator=(const Player &other) {
    // Check for self-assignment.
    if (this == &other)
        return *this;
    
        delete[] name; // <-- (5) Free old name memory

        name = new char[strlen(other.name) + 1]; // Create space in memory to store the player's name (5)
        strcpy(name, other.name);                //string copy (5) copies the name to the allocated space (5)

    // Free the old name memory and allocate new memory for the name.

    // Copy each member variable.
    gamesPlayed = other.gamesPlayed;
    goals = other.goals;
    assists = other.assists;
    wages = other.wages;
    
    // Return the current object by reference.
    return *this;
}
//------------------------------------------------------------------------//

// Destructor (5)
Player::~Player() {
   // cout << "Destructor called for: " << name << endl; // <-- for demonstration
    delete[] name; // <-- (5) Free dynamic memory for name
}

// Mutator set to stop negative wages goals and assists
void Player::setGoals(int g) {
    if (g >= 0) goals = g;
    else cout << "Error: Goals cannot be negative." << endl;
}

void Player::setAssists(int a) {
    if (a >= 0) assists = a;
    else cout << "Error: Assists cannot be negative." << endl;
}

void Player::setWages(double w) {
    if (w >= 0) wages = w;
    else cout << "Error: Wages cannot be negative." << endl;
}

// Shows player details (games played, goals, assists, and wages)
void Player::displayPlayer() const{
    cout << "Player: " << name 
         << " | Games: " << gamesPlayed 
         << " | Goals: " << goals 
         << " | Assists: " << assists 
         << " | Wages: $" << wages 
         << endl;
}

// Override display function
void Player::display() const {
    displayPlayer();
}

// Static Variable that returns the total number of players created
int Player::getPlayerCount() {
    return playerCount;
}

//------------------------------------------------------------------------//
// Overloaded comparison operators (1)
// These operators compare players based on their goals(1)

bool Player::operator==(const Player &other) const { //checks if both players have scored the same number of goals.
    return goals == other.goals;
}

bool Player::operator!=(const Player &other) const { //checks if both players have scored different number of goals.
    return !(*this == other);
}

bool Player::operator<(const Player &other) const { //checks if the current player has scored less goals than the other player.
    return goals < other.goals;
}

bool Player::operator>(const Player &other) const { //checks if the current player has scored more goals than the other player.
    return goals > other.goals;
}


//------------------------------------------------------------------------//
// Overloaded stream operators (2)
// These operators allow for easy input and output of player details

// Overloaded stream insertion operator for output
ostream &operator<<(ostream &os, const Player &player) {
    os << "Name: " << player.name << "\n"
       << "Games Played: " << player.gamesPlayed << "\n"
       << "Goals: " << player.goals << "\n"
       << "Assists: " << player.assists << "\n"
       << "Wages: " << player.wages;
    return os;
}

// Overloaded stream extraction operator for input (2)
istream &operator>>(istream &is, Player &player) {
    

    char temp[100];  // (5) Creates a temporary space to hold the name input
    cout << "Enter name: ";
    is.getline(temp, 100); // (5) Reads the full name into temp

    delete[] player.name; // Create space in memory to store the player's name (5)
    player.name = new char[strlen(temp) + 1]; // (5) Make new space to hold the updated name
    strcpy(player.name, temp); // (5) Copy the new name from temp into the player's name


    cout << "Enter games played: "; // Ask for the number of games played.
    is >> player.gamesPlayed;

    cout << "Enter goals: "; // Ask for the number of goals
    is >> player.goals;

    cout << "Enter assists: "; // Ask for the number of assists.
    is >> player.assists;

    cout << "Enter wages: "; // Ask for the wages.
    is >> player.wages;

    return is;
}