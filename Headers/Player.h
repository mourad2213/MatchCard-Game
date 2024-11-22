#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
class Player
{
private:
    string name;
    int score;

public:
    Player()
    {
        name = "";
        score = 0;
    }
    Player(string n, int s)
    {
        name = n;
        score = s;
    }
  
    void displayScore();
    void setscore(int s);
    int getscore();
};
#endif