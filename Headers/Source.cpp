#include <iostream>
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
void Deck::Shuffle()
{
  int CountSuperCards = 0;
  while (sizeof(cards) / sizeof(Card) != 16)
  {
    int random = (rand() % 8) + 1; // VALUE
    if (random > 6 && CountSuperCards < 4)
    {
      if ()
        CountSuperCards++;
    }
  }
}
void Deck::DisplayGrid()
{
}
