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
            if (cards[i][j] != nullptr) {
                cout << "[" << cards[i][j]->getValue() << "] ";

            } else {
                cout << "[ ] ";
            }
        }
        cout << endl;
    }
}



void Deck::Shuffle() {
    // Shuffle the collection array
    random_device rd;
    mt19937 g(rd());
    shuffle(collection, collection + 16, g);

    // Redistribute shuffled cards to the grid
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cards[i][j] = collection[k++];
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

Card ***Deck::getcards() {
    return cards;
}

void Deck::setcards(Card ***c) {
    cards = c;
}
void Deck::deleteCardAt(int x, int y) {
    if (cards[x][y] != nullptr) {
        delete cards[x][y];  // Free the memory for the card
        cards[x][y] = nullptr; // Set the pointer to nullptr
    }
}
void Game::playTurn(Player *player) {
    if (player->getSkipTurn()==true) {
        cout << player->getName() << "'s turn is skipped due to a penalty!" << endl;
        player->setSkipTurn(false); // Reset skip flag
        return;
    }

    cout << player->getName() << "'s turn!" << endl;

    // Select two cards
    int x1, y1, x2, y2;
    Card *card1 = nullptr, *card2 = nullptr;
    do {
        cout << "Enter the coordinates of the first card (row and column): ";
        cin >> x1 >> y1;
        cout << "Enter the coordinates of the second card (row and column): ";
        cin >> x2 >> y2;

        // Validate input
        if (x1 >= 0 && x1 < 4 && y1 >= 0 && y1 < 4 &&
            x2 >= 0 && x2 < 4 && y2 >= 0 && y2 < 4 &&
            !(x1 == x2 && y1 == y2)) {
            card1 = d->getcards()[x1][y1];
            card2 = d->getcards()[x2][y2];

            if (card1 != nullptr && card2 != nullptr &&
                !card1->getDirection() && !card2->getDirection()) {
                break;
                }
            }

        cout << "Invalid coordinates or cards already revealed. Try again!" << endl;
    } while (true);

    // Reveal the selected cards
    card1->setDirection(true);
    card2->setDirection(true);
    d->DisplayGrid();

    // Check for match and handle effects
    if (card1->getValue() == card2->getValue()) {
        if (card1->getValue() == 7) { // Bonus cards
            handleBonusCard(player, card1, card2, x1, y1, x2, y2);
        } else if (card1->getValue() == 8) { // Penalty cards
            handlePenaltyCard(player, card1, card2, x1, y1, x2, y2);
        } else { // Standard cards
            handleStandardCard(player, x1, y1, x2, y2);
        }
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
            playTurn(player); // Allow an additional turn
        }
    } else {
        player->setscore(player->getscore() + 1);
    }

    // Remove the bonus cards from the grid
    d->deleteCardAt(x1,y1); // Remove card
    d->deleteCardAt(x2,y2);
}
void Game::handleStandardCard(Player* player, int x1, int y1, int x2, int y2) {
    cout << "Standard cards revealed!" << endl;
    cout << "Match found! +" << 1 << " point." << endl;
    player->setscore(player->getscore() + 1);

    // Remove the standard cards from the grid
    d->deleteCardAt(x1, y1); // Hide the card
    d->deleteCardAt(x2, y2); // Hide the card
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
            player->setSkipTurn(true); // Set the skip flag for the next turn
        }
    } else {
        player->setscore(player->getscore() - 1);
    }

    // Remove the penalty cards from the grid
    d->deleteCardAt(x1,y1); // Remove card
    d->deleteCardAt(x2,y2);
}
void Game::startGame() {
    initializeGame();
    Player* currentPlayer = p1;
    while (!isGameOver()) {
        d->DisplayGrid();
        playTurn(currentPlayer);
        currentPlayer = (currentPlayer == p1) ? p2 : p1;
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
int main() {
    Game* game = new Game();
    game->startGame();

    return 0;
}