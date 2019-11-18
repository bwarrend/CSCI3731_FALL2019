#ifndef FISH_H
#define FISH_H
#include "Angle.h"


//Class Fish
//
//
class Fish {

protected:

    int x;
    int y;
    int speed;

    

public:

    Fish(int x, int y, int speed);

    const int getX() const;
    const int getY() const;
    
    virtual void swim() = 0;    

    virtual ~Fish();
};


#endif