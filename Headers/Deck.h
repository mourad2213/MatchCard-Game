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
    Card ***cards; // Grid (2D array of Card pointers)
    Card *collection[16]; // Collection of cards

public:
    Deck() {
        // Allocate a 4x4 grid of Card pointers
        cards = new Card **[4];
        for (int i = 0; i < 4; ++i) {
            cards[i] = new Card *[4];
            for (int j = 0; j < 4; ++j) {
                cards[i][j] = nullptr; // Initialize pointers to nullptr
            }
        }

        // Populate collection with 16 cards
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
        // Deallocate the 2D grid of card pointers
        for (int i = 0; i < 4; ++i) {
            delete[] cards[i]; // Delete each row
        }
        delete[] cards; // Delete the array of row pointers

        // Deallocate cards in the collection
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
