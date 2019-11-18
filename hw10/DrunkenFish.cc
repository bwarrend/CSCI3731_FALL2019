#include <iostream>
#include <cstdlib>
#include "Fish.h"
#include "DrunkenFish.h"

//Constructor:  Create a fish given x and y positions, swim speed, turnrate, initial direction.
//
DrunkenFish::DrunkenFish(int x, int y, int speed)
    :Fish(x, y, speed){
}


//SWIM! 
//
void DrunkenFish::swim(){
    int choice = rand() % 4;
    
    switch(choice){
        case 0: x += speed; break;
        case 1: y += speed; break;
        case 2: x -= speed; break;
        case 3: y -= speed; break;
        default: 
            if(speed >= 1){
                --speed;
            }
            swim();
    }
}

//Destructor
DrunkenFish::~DrunkenFish(){
}