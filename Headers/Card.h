
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
    virtual ~Card();

    void setDirection(bool direction);
    bool getDirection();

    void setNumber(int number);
    int getNumber();
    
    virtual void display();
};

class StandardCard : public Card
{
public:
    StandardCard();
    StandardCard(bool direction, int number)
    {
        setNumber(number);
        setDirection(direction);
    }
    ~StandardCard();
    void display()
    {
        if (getDirection())
        {
            cout << getNumber() << endl;
        }
        else
        {
            cout << "*" << endl;
        }
    }
};

class BonusCard : public Card
{
public:
    BonusCard();
    BonusCard(bool direction, int number)
    {
        setNumber(number);
        setDirection(direction);
    }
    ~BonusCard();
    void display()
    {
        if (getDirection())
        {
            cout << "B" << endl;
        }
        else
        {
            cout << "*" << endl;
        }
    }
};

class PenaltyCard : public Card
{
public:
    PenaltyCard();
    PenaltyCard(bool direction, int number)
    {
        setNumber(number);
        setDirection(direction);
    }
    ~PenaltyCard();
    void display()
    {
        if (getDirection())
        {
            cout << "P" << endl;
        }
        else
        {
            cout << "*" << endl;
        }
    }
};

#endif
