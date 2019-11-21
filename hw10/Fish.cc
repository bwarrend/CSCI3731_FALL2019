#include "Fish.h"

//Constructor:  Create a fish given x and y positions, swim speed, turnrate, initial direction, 
//the population it will be added to, then adds itself to that population.
//
Fish::Fish(int x, int y, int speed)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
}

//Return fishes current X location
//
const int Fish::getX() const {
    return x;
}

//Return fishes current Y location
//
const int Fish::getY() const {
    return y;
}


//Destructor
Fish::~Fish(){
}