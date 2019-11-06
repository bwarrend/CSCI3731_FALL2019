#ifndef FISH_H
#define FISH_H
#include "Angle.h"
class Population;

//Class Fish
//
//
class Fish {

protected:

    int x;
    int y;
    int speed;

    Population& population;
    

public:

    Fish(int x, int y, int speed, Population& popu);

    const int getX() const;
    const int getY() const;
    
    virtual void swim() = 0;    

    virtual ~Fish();
};


#endif