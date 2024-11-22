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
void Card::setNumber(int number)
{
  this->value = number;
}
int Card::getNumber()
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
    cout << cards[i]->getNumber();
    cout << "] ";
  }
  cout << endl;
}

void Deck::Shuffle()
{
  for (int i = 0; i < 16; i++)
  {
    srand(time(0));
    int j = rand() % (15 + 1);
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
  d.Shuffle();
  d.DisplayGrid();
}

int main()
{
  Deck *d = new Deck();
  Game *g = new Game();

  g->initializeGame();

  return 0;
}