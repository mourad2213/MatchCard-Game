#ifndef DECK_H
#define DECK_H
#include<iostream>
using namespace std;
#include"Card.h"
 class Deck{
    private:
    Card** cards = new Card*[4]; 
    public:
     Deck(){
       for (int i = 0; i < 4; i++) {
        cards[i] = new Card[4];  
    }
     }
     Deck(Card** c){
       for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cards[i][j]= c[i][j];
            }
        }
     }
     ~Deck(){
        

     }/*
     Card** getCards(){
            return Card**
     }*/
    

    void Shuffle();
    void DisplayGrid();
    };
#endif