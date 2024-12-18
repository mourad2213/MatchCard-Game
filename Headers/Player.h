#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int score;
    bool skipTurn;
    bool extraTurn;
public:
    Player() {
        this->name = "";
        this->score = 0;
        this->skipTurn = false;
        this->extraTurn = false;
    }

    Player(string n, int s) {
        this->name = n;
        this->score = s;
    }
    ~Player() {}

    void displayScore();

    string getName();

    bool getSkipTurn() ;
    void setSkipTurn(bool skipTurn);
    bool getExtraTurn() ;
    void setExtraTurn(bool extraTurn) ;
    void setName(string n);

    void setscore(int s);

    int getscore();

    void addScore(int s);
    void subtractScore(int s);
};
#endif