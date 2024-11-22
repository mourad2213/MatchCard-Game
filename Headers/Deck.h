#ifndef DECK_H
#define DECK_H
#include<iostream>
using namespace std;
#include"Card.h"
 class Deck{
    private:
    Card** cards = new Card*[4];//grid
    //
    Card* collection[16];//collection
        
    public:
     Deck(){
        for(int m=0;m<16;){
            for(int i=1;i<=8;i++){
                collection[m]=new Card(0,i);//
                m++;
                collection[m]=new Card(0,i);//
            }
        }
     }
     Deck(Card** c){
        c= new Card*[4];
       for(int m=0;m<16;m++){
            for(int i=0;i<8;i++){
                collection[m]= &Card(i,0);
            }
        }
     }
     Deck::~Deck()
        {
            // Delete dynamically allocated cards
            for (int i = 0; i < 16; ++i)
            {
                delete cards[i];
                
            }
            delete[] cards; // Delete the array of pointers
        }

    
    Card**getcards(){
        return cards;
    }
    void setcards(Card** c){
        cards=c;
    }
    void Shuffle();
    void DisplayGrid();
    };
#endif