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

void Card::setDirection(bool direction) {
    this->direction = direction;
}

bool Card::getDirection() {
    return direction;
}

void Card::setValue(int number) {
    this->value = number;
}

int Card::getValue() {
    return this->value;
}

void Card::display() {
    if (this->direction) {
        cout << this->value; // value
    } else {
        cout << "*"; // *
    }
}

void Deck::DisplayGrid() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "[";
            cards[i][j].display();
            cout << "] ";
        }
        cout << endl;
    }
}

void Deck::Shuffle() {
    srand(time(0));
    for (int i = 0; i < 16; i++) {
        int j = rand() % 16;
        swap(collection[i], collection[j]);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cards[i][j] = *collection[i * 4 + j];
        }
    }
}

int Player::getscore() {
    return this->score;
}

void Player::setscore(int s) {
    this->score = s;
}

string Player::getName() {
    return this->name;
}

void Player::setName(string n) {
    this->name = n;
}

void Player::displayScore() {
    cout << this->name << " Score: " << this->score << endl;
}

int BonusCard::getBonus() const {
    return this->bonus;
}

int PenaltyCard::getPenalty() const {
    return this->penalty;
}

void Game::initializeGame() {
    d->Shuffle();
    d->DisplayGrid();
    p1->displayScore();
    p2->displayScore();
}

Card **Deck::getcards() {
    return cards;
}

void Deck::setcards(Card **c) {
    cards = c;
}

int main() {
    Game *g = new Game();

    g->initializeGame();

    delete g;
    return 0;
}
