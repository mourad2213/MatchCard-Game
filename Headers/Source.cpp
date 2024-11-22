#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include <time.h>

void Card::setDirection(bool direction)
{
  this->direction = direction;
}
bool Card::getDirection()
{
  return direction;
}
void Card::setValue(int number)
{
  this->value = number;
}
int Card::getValue()
{
  return this->value;
}
void Card::display()
{
  if (this->direction)
  {
    cout << this->value; // value
  }
  else
  {
    cout << "*"; // *
  }
}

void Deck::DisplayGrid()
{
  for (int i = 0; i < 16; i++)
  {
    if (i % 4 == 0)
    {
      cout << endl;
    }
    cout << "[";
    //cards[i]->display();
    cout<<cards[i]->getValue();
    cout << "] ";
  }
  cout << endl;
}

void Deck::Shuffle()
{
  srand(time(0));
  for (int i = 0; i < 16; i++)
  {
    int j = rand() % (15 + 1); //[1,16]
    swap(collection[i], collection[j]);
  }

  for (int i = 0; i < 16; ++i)
  {
    cards[i] = collection[i];
  }
}

int Player::getscore()
{
  return this->score;
}
void Player::setscore(int s)
{
  this->score = s;
}

void Player::displayScore()
{
  cout << this->score << endl;
}
int BonusCard::getBonus()
{
  return this->bonus;
}
int PenaltyCard::getPenalty()
{
  return this->penalty;
}

void Game::initializeGame()
{
  //Deck* d2 =new Deck();
  d.Shuffle();
  d.DisplayGrid();
}

Card **Deck::getcard()
{
  return cards;
}
void Deck::setcards(Card **c)
{
  cards = c;
}
int main()
{
  Deck *d = new Deck();
  Game *g = new Game();

  g->initializeGame();

  return 0;
}