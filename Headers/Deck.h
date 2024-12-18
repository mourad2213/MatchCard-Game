#ifndef DECK_H
#define DECK_H
#include <iostream>
using namespace std;
#include "Card.h"
#include "BonusCard.h"
#include "StandardCard.h"
#include "PenaltyCard.h"

class Deck {
private:
    Card ***cards; // grid 2d array of card pointer
    Card *collection[16]; // collection

public:
    Deck() {

        cards = new Card **[4];
        for (int i = 0; i < 4; ++i) {
            cards[i] = new Card *[4];
            for (int j = 0; j < 4; ++j) {
                cards[i][j] = nullptr; // null at first
            }
        }


        for (int m = 0; m < 16;) {
            for (int i = 1; i <= 8; i++) {
                if (i == 7) {
                    collection[m] = new BonusCard(0, i);
                    m++;
                    collection[m] = new BonusCard(0, i);
                    m++;
                } else if (i == 8) {
                    collection[m] = new PenaltyCard(0, i);
                    m++;
                    collection[m] = new PenaltyCard(0, i);
                    m++;
                } else {
                    collection[m] = new StandardCard(0, i);
                    m++;
                    collection[m] = new StandardCard(0, i);
                    m++;
                }
            }
        }


    }

    ~Deck() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                delete cards[i][j]; //delete each card pointer inside the first array
            }
            delete[] cards[i];
        }
        delete[] cards;

        // Delete collection of cards
        for (int i = 0; i < 16; ++i) {
            delete collection[i];
        }
    }
    void setcards(Card ***c);
    Card ***getcards();
    void deleteCardAt(int x, int y);
    void Shuffle();
    void DisplayGrid();
};
#endif
