#include <iostream>
using namespace std;
#include "Card.h";
#include "Deck.h";

  void Deck::Shuffle()
  {
    int numbers[16] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    




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
