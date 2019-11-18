#ifndef FLIPPYFISH_H
#define FLIPPYFISH_H
#include "Angle.h"
#include "Fish.h"

//Class FlippyFish
//
//
class FlippyFish : public Fish{

private:

 
    Angle turnRate;
    Angle direction;
    

public:

    FlippyFish(int x, int y, int speed, int turnSpeed, int initialDirection);

    const double getDirection() const;
    void swim();    

    virtual ~FlippyFish();
};


#endif