#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Angle.h"
#include "Fish.h"
#include "Population.h"




int main(){

     
    srand(time(0));


    Population fishList(100000);
    Population& flRef = fishList;

    const int INIT_X = 0;
    const int INIT_Y = 0;

    const int INIT_SWIM_SP = 3;
    const int INIT_TURN_SP = 45;
    const int INIT_DIR = 90;
    
    const int UP_X_BOUND = INIT_X + 100;
    const int LOW_X_BOUND = INIT_X - 100;
    const int UP_Y_BOUND = INIT_Y + 100;
    const int LOW_Y_BOUND = INIT_Y - 100;

    double stepCount = 0;

    
    while(fishList.getPopCount() < fishList.getMaxFishes()){
        new Fish(INIT_X, INIT_Y, INIT_SWIM_SP, INIT_TURN_SP, INIT_DIR, flRef);
        cls();
        std::cout << "Step: " << ++stepCount << std::endl;
        std::cout << "FIRST FISH - X: " << fishList.getFish(0)->getX() << " Y: " << fishList.getFish(0)->getY() << std::endl;        
        std::cout << "Current population: " << fishList.getPopCount() << std::endl;
        std::cout << "Ctrl+C to quit" << std::endl;
        
        int currentPop = fishList.getPopCount();// + 1;
        for(int i = 0 ; i < currentPop; ++i){
            if(fishList.getFish(i) != nullptr){
                Fish* f = fishList.getFish(i);
                if(f->getX() > LOW_X_BOUND && f->getX() < UP_X_BOUND && f->getY() > LOW_Y_BOUND && f->getY() < UP_Y_BOUND){
                    f->swim();
                }else{
                    delete fishList.getFish(i);
                }
            }
        }
    }
    




    return 0;
}