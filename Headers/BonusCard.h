#ifndef BONUSCARD_H
#define BONUSCARD_H
#include <iostream>
#include "Card.h"
using namespace std;

class BonusCard : public Card {
private:
    const int bonus = 1;

public:
    BonusCard() : Card() {
    }

    BonusCard(bool direction, int value) : Card(direction, value) {
    }

    ~BonusCard() {
    }

    int getBonus() const;
};
#endif