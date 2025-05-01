#include "League.h"
#include <iostream>

using namespace std;

League::League() : name(""), clubCount(0) {}

League::League(string name) : name(name), clubCount(0) {}

void League::addClub(Club club) {
    if (clubCount < 5) {
        clubs[clubCount++] = club;
    }
}

void League::displayLeague() {
    cout << "League: " << name << endl;
    for (int i = 0; i < clubCount; i++) {
        clubs[i].displayClub();
    }
}
