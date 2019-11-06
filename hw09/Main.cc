#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Angle.h"
#include "Fish.h"
#include "FlippyFish.h"
#include "DrunkenFish.h"
#include "Population.h"
#include <typeinfo>




int main(){

    //Seed rng set up some constant fish related paramters
    //
    srand(time(0));
    Population fishList(100000);
    Population& flRef = fishList;

    const int INIT_X = 0;
    const int INIT_Y = 0;

    //const int SWIM_SP = 4;
    //const int TURN_SP = 45;
    
    //const int INIT_DIR = 90;
    
    const int UP_X_BOUND = INIT_X + 100;
    const int LOW_X_BOUND = INIT_X - 100;
    const int UP_Y_BOUND = INIT_Y + 100;
    const int LOW_Y_BOUND = INIT_Y - 100;

    double stepCount = 0;

    //While loop so the population doesn't go completely out of control, will stop if too many fish are created
    //
    while(fishList.getPopCount() < fishList.getMaxFishes()){
        //Make a new fish using the constants from above
        //
        
        //new FlippyFish(INIT_X, INIT_Y, rRange(INIT_SWIM_SP_MIN, INIT_SWIM_SP_MAX), rRange(INIT_TURN_SP_MIN,INIT_TURN_SP_MAX), INIT_DIR, flRef);
        new DrunkenFish(INIT_X, INIT_Y, 3, flRef);

        //Print current steps, first fish x and y, and current population
        //
        //cls();
        std::cout << "Step: " << ++stepCount << std::endl;
        std::cout << "FIRST FISH - X: " << fishList.getFish(0)->getX() << " Y: " << fishList.getFish(0)->getY() << std::endl;        
        std::cout << "Current population: " << fishList.getPopCount() << std::endl;
        std::cout << "Ctrl+C to quit" << std::endl;
        
        //For loop over only the created fish, if they exist and are within bounds, run swim().  If OOBs, then delete.
        //
        int currentPop = fishList.getPopCount();// + 1;
        for(int i = 0 ; i < currentPop; ++i){
            if(fishList.getFish(i) != nullptr){
                Fish* f = fishList.getFish(i);
               
                if(f->getX() > LOW_X_BOUND && f->getX() < UP_X_BOUND && f->getY() > LOW_Y_BOUND && f->getY() < UP_Y_BOUND){
                    f->swim();
                }else{
                    DrunkenFish* ff = dynamic_cast<DrunkenFish*>(f);

                    if(ff != nullptr){
                        std::cout << "FLIPPY FLAPPY";
                    }

                    
                   
                    delete fishList.getFish(i);
                }
            }
        }
    }

    return 0;
}