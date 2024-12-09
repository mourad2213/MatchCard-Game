#include <iostream>
using namespace std;
#include "Player.h"
#include "Deck.h"

class Game {
private:
    Player *p1;
    Player *p2;
    Deck *d;

public:
    Game() {
        p2 = new Player("Player 2", 0);
        p1 = new Player("Player 1", 0);
        d = new Deck();
    }

    ~Game() {
        delete p1;
        delete p2;
        delete d;
    }
    void announceWinner(); 
    void initializeGame();
};
