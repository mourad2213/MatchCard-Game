#include <iostream>
using namespace std;
#include "Player.h"
#include "Deck.h"
class Game
{
private:
    Player p1;

    Player p2;

    Deck d;

public:
    Game()
    {
    }
    void initializeGame();
};
