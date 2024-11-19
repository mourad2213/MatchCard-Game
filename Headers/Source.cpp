#include <iostream>
#include <algorithm>
using namespace std;
#include "Card.h";
#include "Deck.h";


void Card::setDirection(bool direction){
  this->direction = direction;
}
bool Card::getDirection(){
  return direction;
}
void Card::setNumber(int number){
  this->value = number;
}
int Card::getNumber(){
  return value;
}
void Card::display() {
    if (this->direction) {
        cout << this->value; //value
    } else {
        cout << "*"; // *
    }
}


















































void Deck::DisplayGrid()
{
}

  void Deck::Shuffle()
  {
    int numbers[16] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    random_shuffle(numbers,numbers+16);
    for(int m =0;m<16;m++){
      for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
          Card card (&numbers[m],0);
          cards[i][j]=card;
        
      }
    }
}
  }