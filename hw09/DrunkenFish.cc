#include <iostream>
#include <cstdlib>
#include "Fish.h"
#include "DrunkenFish.h"
#include "Population.h"

//Constructor:  Create a fish given x and y positions, swim speed, turnrate, initial direction, 
//the population it will be added to, then adds itself to that population.
//
DrunkenFish::DrunkenFish(int x, int y, int speed, Population& popu)
    :Fish(x, y, speed, popu){
}


//SWIM! 
//
void DrunkenFish::swim(){
    int choice = rand() % 4;
    
    if      (choice == 0)   x += speed;
    else if (choice == 1)   y += speed;
    else if (choice == 2)   x -= speed;
    else                    y -= speed;
}

//Destructor: when this fish is deleted, remove itself from the population
DrunkenFish::~DrunkenFish(){
    population.removeFish(this);
}