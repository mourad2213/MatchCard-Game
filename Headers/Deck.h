#ifndef DECK_H
#define DECK_H
#include <iostream>
using namespace std;
#include "Card.h"
#include "BonusCard.h"
#include "StandardCard.h"
#include "PenaltyCard.h"
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
                
                if(i==7){
                collection[m] = new BonusCard(0, i);     
                m++;
                collection[m] = new BonusCard(0, i);    
                m++;
                }
                
                else if(i==8){
                collection[m] = new PenaltyCard(0, i); 
                m++;    
                collection[m] = new PenaltyCard(0, i); 
                m++;
                }
                else{
                collection[m] = new StandardCard(0, i); 
                m++;
                collection[m] = new StandardCard(0, i); 
                m++;
                }
        
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

    void setcards(Card **c);
    Card**getcard();
    void Shuffle();
    void DisplayGrid();
};
#endif