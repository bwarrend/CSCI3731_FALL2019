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
    //Something interesting.  As long as the speed is >=1, the drunk fish
    //has a chance to get tired and its speed will reduce, and then try to
    //swim again
    switch(choice){
        case 0: x += speed; break;
        case 1: y += speed; break;
        case 2: x -= speed; break;
        case 3: y -= speed; break;
        default: 
            if(speed >= 3){
                --speed;
            }
            swim();
    }
}

//Destructor
DrunkenFish::~DrunkenFish(){
}