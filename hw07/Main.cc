#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Angle.h"
#include "Fish.h"
#include "Population.h"




int main(){

     
    srand(time(0));


    Population fishList(5000);
    Population& flRef = fishList;



    while(fishList.getPopCount() < fishList.getMaxFishes()){
        new Fish(0, 0, 3, 45, 90, flRef);
        std::cout << fishList.getPopCount() << std::endl;
        for(int i = 0; i < fishList.getMaxFishes(); ++i){
            if(fishList.getFish(i) != nullptr){
                Fish* fish = fishList.getFish(i);
                if(fish->getX() > -100 && fish->getX() < 100 && fish->getY() > -100 && fish->getY() < 100){
                    fish->swim();
                }else{
                    delete fishList.getFish(i);
                    //std::cout << "DIED" << std::endl;
                }
            }
        }
    }





    return 0;
}