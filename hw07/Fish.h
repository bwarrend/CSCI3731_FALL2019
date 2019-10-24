#ifndef FISH_H
#define FISH_H
#include "Angle.h"
class Population;

//Class Fish
//
//
class Fish {

private:

    int x;
    int y;
    int speed;

    Angle turnRate;
    Angle direction;

    Population& population;

    

public:

    Fish(int x, int y, int speed, int turnSpeed, int initialDirection, Population& popu);

    const int getX() const;
    const int getY() const;
    const double getDirection() const;
    void swim();    

    virtual ~Fish();
};


#endif