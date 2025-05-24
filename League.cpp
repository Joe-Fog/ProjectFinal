#include "League.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
//-----------------------Save File -----------------------------------
void League::saveFile(const string& filename) const {
    ofstream out(filename);
    if (!out) {
        cerr << "Could not open " << filename << " for writing\n";
        return;
    }

    out << "# League\n" << name << "\n\n";

    for (int c = 0; c < clubCount; ++c) {
        const Club& club = clubs[c];

        out << "# Club\n";
        out << club.getName() << '\n';
        out << club.getRecord().getMatchesPlayed() << ' '
            << club.getRecord().getTrophiesWon()   << '\n';

        for (int p = 0; p < club.getPlayerCount(); ++p) {
            const Player& pl = club.getPlayer(p);
            out << pl.getName()        << ';'
                << pl.getGamesPlayed() << ';'
                << pl.getGoals()       << ';'
                << pl.getAssists()     << ';'
                << pl.getWages()       << '\n';
        }
        out << "END_CLUB\n\n";
    }
    out << "END_FILE\n";


}
void League::loadFile(const string& filename)
{
    ifstream in(filename);
    if (!in)
    {
        cerr << "Could not open " << filename << " for reading\n";
        return;
    }

    clubCount = 0;              // start fresh
    string line;

    // read first two lines: "# League" and league name
    getline(in, line);          // discard "# League"
    getline(in, name);          // league name

    while (getline(in, line))
    {
        if (line == "# Club")
        {
            string clubName;
            getline(in, clubName);               // club name

            int mp, tw;
            in >> mp >> tw;  in.ignore();        // record line
            Club cl(clubName, Record(mp, tw));   // new club

            while (getline(in, line) && line != "END_CLUB")
            {
                if (line.empty()) continue;
                stringstream ss(line);
                string pname; int gms, gls, ast; double w;
                getline(ss, pname, ';');
                ss >> gms; ss.ignore(); ss >> gls; ss.ignore();
                ss >> ast; ss.ignore(); ss >> w;

                cl.addPlayer(Player(pname.c_str(), gms, gls, ast, w));
            }
            addClub(cl);        // put rebuilt club in league
        }
        else if (line == "END_FILE")
            break;
    }
}