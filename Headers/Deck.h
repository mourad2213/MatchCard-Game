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
       for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cards[i][j] = new Card(c[i][j]); 
            }
        } 
     }
     ~Deck();
    void Shuffle();
    void DisplayGrid();
    };
#endif