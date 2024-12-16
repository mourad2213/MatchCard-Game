#include <iostream>
using namespace std;
#include "Player.h"
#include "Deck.h"

class Game {
private:
    Player *p1;
    Player *p2;
    Deck *d;
    Player* currentPlayer;


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

void switchTurn();
    void handleCardPair(Card* card1, Card* card2);
    void handleStandardCards(Card* card1, Card* card2);
    void handleBonusCards(Card* card1, Card* card2);
    void handlePenaltyCards(Card* card1, Card* card2);
    void initializeGame();

    void playTurn(Player *player);

    void handleBonusCard(Player *player, Card *card1, Card *card2, int x1, int y1, int x2, int y2);

    void handlePenaltyCard(Player *player, Card *card1, Card *card2, int x1, int y1, int x2, int y2);

    void startGame();

    bool isGameOver();

    void announceWinner();

    void playGame();
    void announceWinner() const;
};
