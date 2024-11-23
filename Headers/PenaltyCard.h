#ifndef PENALTYCARD_H
#define PENALTYCARD_H
#include <iostream>
#include "Card.h"
using namespace std;

class PenaltyCard : public Card {
private:
    const int penalty = -1;

public:
    PenaltyCard() : Card() {
    }

    PenaltyCard(bool direction, int value) : Card(direction, value) {
    }

    int getPenalty();
};
#endif
