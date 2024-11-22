#ifndef DECK_H
#define DECK_H
#include <iostream>
using namespace std;
#include "Card.h"
class Deck
{
private:
    Card **cards = new Card *[4]; // grid
    //
    Card *collection[16]; // collection

public:
    Deck()
    {
        for (int m = 0; m < 16;)
        {
            for (int i = 1; i <= 8; i++)
            {
                collection[m] = new Card(0, i); //
                m++;
                collection[m] = new Card(0, i); //
            }
        }
    }
    
    ~Deck()
    {
        
        for (int i = 0; i < 16; ++i)
        {
            delete collection[i];
        }
        delete[] cards; 
    }

    Card **getcards()
    {
        return cards;
    }
    void setcards(Card **c)
    {
        cards = c;
    }
    void Shuffle();
    void DisplayGrid();
};
#endif