#include <iostream>
#include <cstdlib>
#include "Fish.h"
#include "Angle.h"
#include "Population.h"

//Constructor:  Create a fish given x and y positions, swim speed, turnrate, initial direction, 
//the population it will be added to, then adds itself to that population.
//
Fish::Fish(int x, int y, int speed, int turnSpeed, int initialDirection, Population& popu)
    :turnRate(turnSpeed),
    direction(initialDirection),
    population(popu){
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

//Return a fishes current direction
//
const double Fish::getDirection() const {
    return direction.getAngle();
}

//SWIM! Possibly turn and then swim in that direction
//
void Fish::swim(){
    int choice = rand() % 3;
    
    if(choice == 0){
        direction -= turnRate;
    }else if(choice == 3){
        direction -= turnRate;
    }

    x += speed * direction.getCos();
    y += speed * direction.getSin();
}

//Destructor: when this fish is deleted, remove itself from the population
Fish::~Fish(){
    population.removeFish(this);
}