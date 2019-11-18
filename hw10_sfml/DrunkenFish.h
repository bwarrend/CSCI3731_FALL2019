#ifndef DRUNKENFISH_H
#define DRUNKENFISH_H
#include "Fish.h"

//Class DrunkenFish
//
//
class DrunkenFish : public Fish{

private:
   

public:

    DrunkenFish(int x, int y, int speed);

    void swim();    

    virtual ~DrunkenFish();
};


#endif