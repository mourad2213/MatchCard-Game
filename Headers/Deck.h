#ifndef DECK_H
#define DECK_H
#include<iostream>
using namespace std;
#include"Card.h"
 class Deck{
    protected:
    Card cards[4][4];
    public:
    void Shuffle();
     void DisplayGrid();
    };
#endif