#include <iostream>
using namespace std;
#include "Card.h";
#include "Deck.h";
Card::Card(){}
Card::Card(bool direction, int value){}
Card::~Card(){}

class Deck : public Card
{
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
};

class Player
{
};

class Game
{
};
