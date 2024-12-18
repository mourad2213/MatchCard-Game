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
            if (cards[i][j] != nullptr) {
                cout << "[";
                    cards[i][j]->display();
                cout<< "] ";

            } else {
                cout << "[ ] ";
            }
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
            cards[i][j] = collection[i * 4 + j];
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

int BonusCard::getBonus() {
    return this->bonus;
}

int PenaltyCard::getPenalty() {
    return this->penalty;
}
bool Player::getSkipTurn() {
    return this->skipTurn;
}
void Player::setSkipTurn(bool skipTurn) {
    this->skipTurn = skipTurn;
}
bool Player::getExtraTurn() {
    return this->extraTurn;
}
void Player::setExtraTurn(bool extraTurn) {
    this->extraTurn = extraTurn;
}
void Player::addScore(int s) {
    this->score += s;
}
void Player::subtractScore(int s) {
    this->score -= s;
}
void Game::initializeGame() {
    d->Shuffle();
    d->DisplayGrid();
    p1->displayScore();
    p2->displayScore();
}
void Card::reveal() {
    this->direction = true;
}
void Card::hide() {
    this->direction = false;
}
bool Card::isRevealed() {
    return direction;
}
Card ***Deck::getcards() {
    return cards;
}

void Deck::setcards(Card ***c) {
    cards = c;
}
void Deck::deleteCardAt(int x, int y) {
    if (cards[x][y] != nullptr) {
        delete cards[x][y];
        cards[x][y] = nullptr;
    }
}
void Game::playerTurn(Player *player) {
    if (player->getSkipTurn()==true) {
        cout << player->getName() << " turn is skipped due to a penalty" << endl;
        player->setSkipTurn(false);
        return;
    }

    cout << player->getName() << " turn" << endl;
    int x1;
    int y1;
    int x2;
    int y2;
    Card *card1 = nullptr;
    Card *card2 = nullptr;
    while(true) {
        cout << "Enter the coordinates of the first card (row and column): ";
        while (!(cin >> x1 >> y1)) {
            cout << "Invalid input! Please enter numeric values for row and column." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the coordinates of the first card (row and column): ";
        }

        cout << "Enter the coordinates of the second card (row and column): ";


        while (!(cin >> x2 >> y2)) {
            cout << "Invalid input! Please enter numeric values for row and column." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the coordinates of the second card (row and column): ";
        }

        if (x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 && x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4 && !(x1 == x2 && y1 == y2)) {
            card1 = d->getcards()[x1][y1];
            card2 = d->getcards()[x2][y2];

            if (card1 != nullptr && card2 != nullptr &&
                !card1->getDirection() && !card2->getDirection()) {
                break;
                }
            }

        cout << "Invalid coordinates or cards already revealed. Try again!" << endl;
    }


    card1->setDirection(true);
    card2->setDirection(true);
    d->DisplayGrid();


    if (card1->getValue() == card2->getValue()) {
        if (card1->getValue() == 7) { //bonus
            handleBonusCard(player, card1, card2, x1, y1, x2, y2);
        } else if (card1->getValue() == 8) { // penalty
            handlePenaltyCard(player, card1, card2, x1, y1, x2, y2);
        } else { // standard
            handleStandardCard(player, x1, y1, x2, y2);
        }
        playerTurn(player);
    } else {
        cout << "No match! Cards will be hidden again." << endl;
        card1->setDirection(false);
        card2->setDirection(false);
    }

    player->displayScore();
}


void Game::handleBonusCard(Player* player, Card* card1, Card* card2, int x1, int y1, int x2, int y2) {
    cout << "Bonus cards revealed!" << endl;
    if (card1->getValue() == card2->getValue()) {
        cout << "Choose one option:\n1. Gain 2 points\n2. Gain 1 point and take another turn." << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            player->setscore(player->getscore() + 2);
        } else if (choice == 2) {
            player->setscore(player->getscore() + 1);
            playerTurn(player); // additional turn
        }
    } else {
        player->setscore(player->getscore() + 1);
    }

    d->deleteCardAt(x1,y1);
    d->deleteCardAt(x2,y2);
}
void Game::handleStandardCard(Player* player, int x1, int y1, int x2, int y2) {
    cout << "Standard cards revealed!" << endl;
    cout << "Match found! +" << 1 << " point." << endl;
    player->setscore(player->getscore() + 1);


    d->deleteCardAt(x1, y1);
    d->deleteCardAt(x2, y2);
}

void Game::handlePenaltyCard(Player* player, Card* card1, Card* card2, int x1, int y1, int x2, int y2) {
    cout << "Penalty cards revealed!" << endl;
    if (card1->getValue() == card2->getValue()) {
        cout << "Choose one option:\n1. Lose 2 points\n2. Lose 1 point and skip next turn." << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            player->setscore(player->getscore() - 2);
        } else if (choice == 2) {
            player->setscore(player->getscore() - 1);
            player->setSkipTurn(true); // skip turn
        }
    } else {
        player->setscore(player->getscore() - 1);
    }

    d->deleteCardAt(x1,y1);
    d->deleteCardAt(x2,y2);
}
void Game::startGame() {
    initializeGame();
    Player* currentPlayer = p1;
    while (!isGameOver()) {
        d->DisplayGrid();
        playerTurn(currentPlayer);
    }
    announceWinner();
}

bool Game::isGameOver() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (d->getcards()[i][j] != nullptr && !d->getcards()[i][j]->getDirection()) {
                return false;
            }
        }
    }
    return true;
}

void Game::announceWinner() {
    cout << "Game over!" << endl;
    p1->displayScore();
    p2->displayScore();
    if (p1->getscore() > p2->getscore()) {
        cout << p1->getName() << " wins!" << endl;
    } else if (p2->getscore() > p1->getscore()) {
        cout << p2->getName() << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
