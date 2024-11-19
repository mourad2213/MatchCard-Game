#ifndef DECK_H
#define DECK_H
#include<iostream>
using namespace std;
#include"Card.h"
 class Deck{
    private:
    Card* cards[4][4];
    public:
     Deck(){
     }
     Deck(Card c[4][4]){
      this->cards=c;  
     }
     ~Deck();
    void Shuffle();
    void DisplayGrid();
    };
#endif