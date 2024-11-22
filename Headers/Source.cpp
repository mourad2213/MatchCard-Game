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
  return value;
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
  cout << "Deck Layout (4x4 Grid):" << endl;
  for (int i = 0; i < 16; i++)
  {
    if (i % 4 == 0)
      cout << endl;

    cout << "[";
    cards[i]->display();
    cout << "] ";
  }
  cout << endl;
}

void Deck::Shuffle()
{
  // Use a random device and Mersenne Twister for randomness
  std::random_device rd; // Random device
  std::mt19937 g(rd());  // Seeded random number generator

  // Shuffle the collection of cards
  std::shuffle(collection, collection + 16, g);

  // Optionally, map shuffled collection back to grid (if needed)
  for (int i = 0; i < 16; ++i)
  {
    cards[i] = collection[i];
  }

  cout << "Deck shuffled!" << endl;
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