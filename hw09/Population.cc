#include <iostream>
#include "Population.h"
#include "Fish.h"

//Constructor: Use arg to make array of pointers of fish
//
Population::Population(int maxFishes){
    this->maxFishes = maxFishes;
    fishList = new Fish*[maxFishes];
    popCount = 0;
}

//Add a fish at the next available non-nullptr slot
//
void Population::addFish(Fish* fish){    
    for(int i = 0; i < maxFishes; ++i){
        if(fishList[i] == nullptr){
            fishList[i] = fish;
            ++popCount;
            return;
        }
    }    
}

//Remove fish based on index
//
void Population::removeFish(int index){
    --popCount;
    fishList[index] = nullptr;
}

//Remove fish based on a reference to a fish, using the index method above
//
void Population::removeFish(Fish* fish){
    for(int i = 0; i < maxFishes; ++i){
        if(fishList[i] == fish){
            removeFish(i);
            return;
        }
    }
}

//Return reference to a fish based on index provided
//
Fish* Population::getFish(int index) const{
    return fishList[index];
}

//Return how many fish exist
//
const int Population::getPopCount() const{
     return popCount;
}

//Return array size
//
const int Population::getMaxFishes() const{
     return maxFishes;
}

//Destructor
//
Population::~Population(){}


//Function for Quality of life
//
  //Clear screen function
  //
    void cls()
    {
        printf("\e[1;1H\e[2J");
    }

    //Return random number based on range
    //
    int rRange(int min, int max){
        return (rand() % (max-(min-1))) + min;
    }