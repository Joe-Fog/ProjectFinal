#ifndef RECORD_H
#define RECORD_H
using namespace std;

class Record { //clubs historical record
private:
    int matchesPlayed;
    int trophiesWon;
    static const int TOTAL_MATCHES = 38; // Constant for total league matches
public:
    Record(); // Default constructor
    Record(int played, int trophies);
    void displayRecord() const;
};

#endif
