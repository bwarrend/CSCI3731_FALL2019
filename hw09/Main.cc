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
    const int MAX_POP = 20000;
    Population fishList(MAX_POP);
    Population& flRef = fishList;

    //Both fish initial values
    //
    const int INIT_X = 0;
    const int INIT_Y = 0;
    const int UP_X_BOUND = INIT_X + 100;
    const int LOW_X_BOUND = INIT_X - 100;
    const int UP_Y_BOUND = INIT_Y + 100;
    const int LOW_Y_BOUND = INIT_Y - 100;
    const int INIT_POPULATION = MAX_POP / 2;

    //FlippyFishOnly.com
    //
    const int SWIM_SP = 4;
    const int TURN_SP = 45;    
    const int INIT_DIR = 90;


    int flippyCount = INIT_POPULATION-3000;

    for (int i = 0; i < flippyCount; ++i){
        new FlippyFish(INIT_X, INIT_Y, SWIM_SP, TURN_SP, INIT_DIR, flRef);    
    }

    
    int drunkyCount = INIT_POPULATION;
    for(int i = 0; i < drunkyCount; ++i){
        new DrunkenFish(INIT_X, INIT_Y, SWIM_SP, flRef);
    }



    while(flippyCount > 0 && drunkyCount > 0){
        for(int i = 0 ; i < MAX_POP; ++i){
            if(fishList.getFish(i) != nullptr){
                Fish* f = fishList.getFish(i);
               
                if(f->getX() > LOW_X_BOUND && f->getX() < UP_X_BOUND && f->getY() > LOW_Y_BOUND && f->getY() < UP_Y_BOUND){
                    f->swim();
                }else{
                    FlippyFish* ff = dynamic_cast<FlippyFish*>(f);
                    if(ff != nullptr){
                        --flippyCount;
                    }else{
                        --drunkyCount;
                    }                   
                    delete fishList.getFish(i);
                }
            }
        }

        cls();
        std::cout << "**FlippyFish VS DrunkenFish**" << std::endl;
        std::cout << "Total Population: " << fishList.getPopCount() << std::endl;
        std::cout << "FlippyFish Remaining: " << flippyCount << std::endl;
        std::cout << "DrunkenFish Remaining: " << drunkyCount << std::endl;
        
    }

    if(flippyCount > drunkyCount){
        std::cout << std::endl << "Flippys are victorious!" << std::endl;
    }else if(drunkyCount > flippyCount){
        std::cout << std::endl << "Drunkys are victorious!" << std::endl;
    }else{
        std::cout << std::endl << "Miraculously, a draw.." << std::endl; 
    }

    return 0;
}