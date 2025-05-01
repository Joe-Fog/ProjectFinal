#include "League.h"
#include "Club.h"
#include "Player.h"
#include "Record.h"
#include "Exceptions.h"
#include <iostream>
#include "Person.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

int main() { //make league, clubs, and players
    League premierLeague("Premier League");

    Club liverpool("Liverpool", Record(25, 19));
    liverpool.addPlayer(Player("Mo Salah", 25, 15, 10, 200000));
    liverpool.addPlayer(Player("Virgil van Dijk", 22, 3, 2, 150000));

    Club manCity("Manchester City", Record(25, 16));
    manCity.addPlayer(Player("Kevin De Bruyne", 20, 5, 18, 300000));
    manCity.addPlayer(Player("Erling Haaland", 23, 25, 5, 400000));

    Club manUnited("Manchester United", Record(25, 20));
    manUnited.addPlayer(Player("Bruno Fernandes", 24, 10, 12, 250000));
    manUnited.addPlayer(Player("Amad Diallo", 22, 12, 8, 200000));

    Club arsenal("Arsenal", Record(25, 14));
    arsenal.addPlayer(Player("Bukayo Saka", 26, 8, 11, 180000));
    arsenal.addPlayer(Player("Martin Odegaard", 25, 14, 15, 220000));

    Club chelsea("Chelsea", Record(25, 18));
    chelsea.addPlayer(Player("Cole Palmer", 23, 9, 7, 250000));
    chelsea.addPlayer(Player("Enzo Fernandez", 21, 3, 10, 200000));
    chelsea.addPlayer(Player("Nicolas Jackson", 12, 6, 2, 800000));


     // ----------------- Handling for user-defined exception types -----------------
     cout << "\n--- User-Defined Exception Test: Duplicate Player ---\n";
     try {
         cout << "Attempting to add Mo Salah again to Liverpool...\n";
         liverpool.addPlayer(Player("Mo Salah", 25, 15, 10, 200000));
     }
     catch (const DuplicatePlayerException &e) {
         cerr << "Caught DuplicatePlayerException: " << e.what() << "\n\n";
     }
     

    premierLeague.addClub(liverpool);
    premierLeague.addClub(manCity);
    premierLeague.addClub(manUnited);
    premierLeague.addClub(arsenal);
    premierLeague.addClub(chelsea);

    premierLeague.displayLeague(); //show league details before sorting
 
    //Final Project adding sort function <--------------------------------------------------------------------------------------------------------(1)

    premierLeague.sortClubsByName();

    cout << "\n=== After sorting ===\n";
    premierLeague.displayLeague();  // show league details after sorting

    // Sort this club’s players by goals scored <—------------------------------------------------------------------------------------------------(2)
   
    arsenal.sortPlayersByGoals();      // or whichever club you’re demoing
    cout << "\nArsenal players sorted by goals:\n";
    arsenal.displayClub();             // should now list Bukayo Saka (14) before Odegaard (8)


    // Sorting all clubs by players by goals scored <---------------------------------------------------------------------------------------------(2)
    /*
    for (int i = 0; i < premierLeague.getClubCount(); ++i) {
        premierLeague.getClub(i).sortPlayersByGoals();
    }
    cout << "\n=== League after sorting each roster by goals ===\n";
    premierLeague.displayLeague();
    
*/


    // Searching for a player in a club <--------------------------------------------------------------------------------------------------------(3)
    cout << "\n=== Finding a player ===\n";
    Player* found = liverpool.findPlayer("Mo Salah");
     if (found) {
         cout << "Found: ";
         found->displayPlayer();
     } else {
        cout << "Player not found.\n";
        }



    //using player class and pointers to show a star player
    cout << "\n Star Man " << endl;
    Person* p1 = new Player("Evan Ferguson", 30, 20, 10, 500000);
    p1->display(); // Calls Player's displayPlayer()
    delete p1;

    //showing players created
    cout << "\nTotal Players Created: " << Player::getPlayerCount() << endl;

/*

//---------------------------Assignement 2---------------------------------------// 

    /// Test for Overloaded Comparison Operators in Player (1)

    // Create two player objects for testing
    Player player1("James Madison", 10, 8, 4, 100000);
    Player player2("Rasmus Hojlund", 12, 12, 5, 120000);

    cout << "\n--- Player Comparison Test ---\n";

    // Compare using overloaded operators (based on 'goals')
    if (player1 < player2) {
        cout << "James Madison has fewer goals than Rasmus Hojlund.\n";
    }
    if (player1 > player2) {
        cout << "James Madison has more goals than Rasmus Hojlund.\n";
    }
    if (player1 == player2) {
        cout << "James Madison and Rasmus Hojlund have the same number of goals.\n";
    }
    if (player1 != player2) {
        cout << "James Madison and Rasmus Hojlund have different number of goals.\n";
    }

    // This test confirms that the overloaded operators for 'Player' work as expected.

//------------------------------------------------------------------//

    /// Test for Overloaded Stream Operators in Player (2)
     cout << "\n--- Player Stream Operators Test ---\n";
    
     // Create a new player using the default constructor
    Player streamPlayer;
 
    // Use the overloaded extraction operator to input details for the new player
    cout << "Enter details for a new player:" << endl;
     cin >> streamPlayer;
 
     // Use the overloaded insertion operator to display the player's details
     cout << "\nNew player details:" << endl;
    cout << streamPlayer << endl;
  
//------------------------------------------------------------------//

    /// Test for Copy Constructor (Deep Copy) (3)
    cout << "\n--- Copy Constructor Test ---\n"; 
    
    // Create an original player
    Player original("Rasmus Hojlund", 12, 12, 5, 120000);
  
    // Create a copy of the original using the copy constructor
    Player copiedPlayer(original);
  
    // Display both the original and the copied player's details
    cout << "Original player details:" << endl;
    cout << original << endl;
  
    cout << "\nCopied player details:" << endl;
    cout << copiedPlayer << endl;

    // This test confirms that the copy constructor creates a deep copy of the player object.

//----------------------------------------------------------------------//

    /// Test for Overloaded Assignment Operator (Deep Copy) (4)
    cout << "\n--- Assignment Operator Test ---\n";
    
    // Create an original player for assignment testing
    Player assignOriginal("Mo Salah", 25, 15, 10, 200000);

    // Create another player false
    Player assignPlayer("Null", 0, 0, 0, 0);
    
    // Use the overloaded assignment operator to copy assignOriginal into assignPlayer
    assignPlayer = assignOriginal;
    
    // Display both the original and the assigned player's details
    cout << "Original (for assignment) player details:" << endl;
    cout << assignOriginal << endl;
    
    cout << "\nAssigned player details:" << endl;
    cout << assignPlayer << endl;


   
    // This test confirms that the overloaded assignment operator creates a deep copy of the player object.
    
     // --------------------------------------------------------------------------------------------------//
    /// Test for Destructor (Dynamic Memory Cleanup) (5)
    cout << "\n--- Destructor Test ---\n";
    Player* dynamicPlayer = new Player("Temp Player", 5, 1, 1, 50000);
    cout << "Dynamic player created and displayed:" << endl;
    cout << *dynamicPlayer << endl;
    delete dynamicPlayer; // <-- Destructor will be called here
     // --------------------------------------------------------------------------------------------------//
*/
    
    // ----------------- Handling for built in exception types -----------------
    cout << "\n--- Built-in Exception Test ---\n";
    
    try {
        // Attempt to convert a non-numeric string to int:
        int number = stoi("not_a_number");  //stoi - string to-int conversion
        cout << "Converted number: " << number << "\n";
    }
    catch (const invalid_argument &e) {
        // Catch the built-in exception and print its message
        cout << "Caught invalid_argument: " << e.what() << "\n";
    }


    return 0;
}
