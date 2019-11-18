#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Angle.h"
#include "Fish.h"
#include "FlippyFish.h"
#include "DrunkenFish.h"
#include <vector>
#include <typeinfo>

void cls()
{
    printf("\e[1;1H\e[2J");
}

int main(){

    //Seed rng set up some constant fish related paramters
    //
    srand(time(0));
    const auto MAX_POP = 20000;

    
    //Both fish initial values
    //
    const auto INIT_X = 0;
    const auto INIT_Y = 0;
    const auto UP_X_BOUND = INIT_X + 1000;
    const auto LOW_X_BOUND = INIT_X - 1000;
    const auto UP_Y_BOUND = INIT_Y + 1000;
    const auto LOW_Y_BOUND = INIT_Y - 1000;

    //FlippyFishOnly
    //
    const auto SWIM_SP = 10;
    const auto TURN_SP = 45;    
    const auto INIT_DIR = 90;


    auto flippyCount = 0;
    auto drunkyCount = 0;

    std::vector<Fish*> fishList;

    for(int i = 0; i < MAX_POP; ++i){
        FlippyFish* flippy = new FlippyFish(INIT_X, INIT_Y, SWIM_SP, TURN_SP, INIT_DIR);
        fishList.push_back(flippy);
        ++flippyCount;
        ++i;
        DrunkenFish* drunky = new DrunkenFish(INIT_X, INIT_Y, SWIM_SP);
        fishList.push_back(drunky);
        drunkyCount++;        
    }
    

    while(flippyCount > 0 && drunkyCount > 0){
    for(int i = 0 ; i < MAX_POP; ++i){
        if(fishList[i] != nullptr){
            Fish* f;
            f = fishList[i];            
            if(f->getX() > LOW_X_BOUND && f->getX() < UP_X_BOUND && f->getY() > LOW_Y_BOUND && f->getY() < UP_Y_BOUND){
                f->swim();
            }else{
                FlippyFish* ff = dynamic_cast<FlippyFish*>(f);
                if(ff != nullptr){
                    --flippyCount;
                }else{
                    --drunkyCount;
                }
                   
                delete fishList[i];
                fishList[i] = nullptr;
            }
        }
    }

        cls();
        std::cout << "**FlippyFish VS DrunkenFish**" << std::endl;
        std::cout << "Total Population: " << drunkyCount + flippyCount << std::endl;
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