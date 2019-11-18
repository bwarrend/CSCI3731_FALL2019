#include <cstdlib>
#include "Fish.h"
#include "FlippyFish.h"
#include "Angle.h"

//Constructor:  Create a fish given x and y positions, swim speed, turnrate, initial direction, 
//the population it will be added to, then adds itself to that population.
//
FlippyFish::FlippyFish(int x, int y, int speed, int turnSpeed, int initialDirection)
    :Fish(x, y, speed),
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

    //Something interesting, 25% chance to go in the same direction a second time
    choice = rand() % 4;    
    if(choice == 2){
        x += speed * direction.getCos();
        y += speed * direction.getSin();
    }
}

//Destructor
FlippyFish::~FlippyFish(){
}