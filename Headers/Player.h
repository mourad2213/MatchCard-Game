#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int score;

public:
    Player() {
        this->name = "";
        this->score = 0;
    }

    Player(string n, int s) {
        this->name = n;
        this->score = s;
    }

    void displayScore();

    string getName();

    void setName(string n);

    void setscore(int s);

    int getscore();
};
#endif
