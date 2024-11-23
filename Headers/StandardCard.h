#ifndef STANDARDCAR_H
#define STANDARDCAR_H
#include <iostream>
#include "Card.h"
using namespace std;

class StandardCard : public Card {
public:
    StandardCard() : Card() {
    }

    StandardCard(bool direction, int value) : Card(direction, value) {
    }
    ~StandardCard() {}
};
#endif
