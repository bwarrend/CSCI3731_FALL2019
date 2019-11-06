#include <iostream>
#include <cstdlib>
#include "Fish.h"
#include "FlippyFish.h"
#include "Angle.h"
#include "Population.h"

//Constructor:  Create a fish given x and y positions, swim speed, turnrate, initial direction, 
//the population it will be added to, then adds itself to that population.
//
FlippyFish::FlippyFish(int x, int y, int speed, int turnSpeed, int initialDirection, Population& popu)
    :Fish(x, y, speed, popu),
    turnRate(turnSpeed),
    direction(initialDirection){

}



//Return a fishes current direction
//
const double FlippyFish::getDirection() const {
    return direction.getAngle();
}

//SWIM! Possibly turn and then swim in that direction
//
void FlippyFish::swim(){
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
FlippyFish::~FlippyFish(){
    population.removeFish(this);
}