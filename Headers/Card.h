
#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
class Card
{
private:
    bool direction; // 0 is not flipped ,1 flipped
    int value;

public:
    Card()
    {
        this->direction = 0;
        this->value = 0;
    }
    Card(bool direction, int number)
    {
        this->direction = direction;
        this->value = number;
    }
    ~Card(){
        
    }

    void setDirection(bool direction);
    bool getDirection();
    void setNumber(int number);
    int getNumber();
    
    void display(); //not done
};

#endif
