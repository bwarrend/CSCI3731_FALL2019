#ifndef DRUNKENFISH_H
#define DRUNKENFISH_H
#include "Fish.h"
class Population;

//Class DrunkenFish
//
//
class DrunkenFish : public Fish{

private:
   

public:

    DrunkenFish(int x, int y, int speed, Population& popu);

    void swim();    

    virtual ~DrunkenFish();
};


#endif