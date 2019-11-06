#include <iostream>
#include <cstdlib>
#include "Fish.h"
#include "Population.h"

//Constructor:  Create a fish given x and y positions, swim speed, turnrate, initial direction, 
//the population it will be added to, then adds itself to that population.
//
Fish::Fish(int x, int y, int speed, Population& popu)
    :population(popu){
    this->x = x;
    this->y = y;
    this->speed = speed;
    population.addFish(this);
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


//Destructor: when this fish is deleted, remove itself from the population
Fish::~Fish(){
    population.removeFish(this);
}