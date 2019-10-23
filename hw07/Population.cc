#include <iostream>
#include "Population.h"
#include "Fish.h"

Population::Population(int maxFishes){
    this->maxFishes = maxFishes;
    fishList = new Fish*[maxFishes];
    popCount = 0;
}

void Population::addFish(Fish* fish){
    
    for(int i = 0; i < maxFishes; ++i){
        if(fishList[i] == nullptr){
            fishList[i] = fish;
            ++popCount;
            return;
        }
    }    
}

void Population::removeFish(int index){
    --popCount;
    fishList[index] = nullptr;
}

void Population::removeFish(Fish* fish){
    for(int i = 0; i < maxFishes; ++i){
        if(fishList[i] == fish){
            removeFish(i);
            return;
        }
    }
}

Fish* Population::getFish(int index) const{
    return fishList[index];
}

 const int Population::getPopCount() const{
     return popCount;
 }

  const int Population::getMaxFishes() const{
     return maxFishes;
 }




void Population::printSomething() const{
    for(int i = 0; i < maxFishes; ++i){
        if(fishList[i] != nullptr){
            std::cout << i << " X: " << fishList[i]->getX() << std::endl;
        }
    }
}
















Population::~Population(){}