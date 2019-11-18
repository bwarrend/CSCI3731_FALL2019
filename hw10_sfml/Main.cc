#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Angle.h"
#include "Fish.h"
#include "FlippyFish.h"
#include "DrunkenFish.h"
#include <vector>
#include <typeinfo>
#include <SFML/Graphics.hpp>

void cls()
{
    printf("\e[1;1H\e[2J");
}

int main(){


    sf::RenderWindow window(sf::VideoMode(1000,1000), "Fish Sim");
    sf::RectangleShape water(sf::Vector2f(1000.f,1000.f));
    water.setPosition(0, 0);
    water.setFillColor(sf::Color::Blue);
    sf::RectangleShape cFish(sf::Vector2f(5.f,2.f));
    


    //Seed rng set up some constant fish related paramters
    //
    srand(time(0));
    const auto MAX_POP = 200;

    
    //Both fish initial values
    //
    const auto INIT_X = 0;
    const auto INIT_Y = 0;
    const auto UP_X_BOUND = INIT_X + 500;
    const auto LOW_X_BOUND = INIT_X - 500;
    const auto UP_Y_BOUND = INIT_Y + 500;
    const auto LOW_Y_BOUND = INIT_Y - 500;

    //FlippyFishOnly
    //
    const auto SWIM_SP = 3;
    const auto TURN_SP = 45;    
    const auto INIT_DIR = 90;


    auto flippyCount = 0;
    auto drunkyCount = 0;

    std::vector<Fish*> fishList;

    for(int i = 0; i < MAX_POP; ++i){
        FlippyFish* flippy = new FlippyFish(INIT_X, INIT_Y, SWIM_SP+2, TURN_SP, INIT_DIR);
        fishList.push_back(flippy);
        ++flippyCount;
        ++i;
        DrunkenFish* drunky = new DrunkenFish(INIT_X, INIT_Y, SWIM_SP);
        fishList.push_back(drunky);
        drunkyCount++;        
    }
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //window.draw(water);

        while(flippyCount > 0 && drunkyCount > 0){

            window.draw(water);

            for(int i = 0 ; i < MAX_POP; ++i){
                if(fishList[i] != nullptr){
                    Fish* f;
                    f = fishList[i];            
                    if(f->getX() > LOW_X_BOUND && f->getX() < UP_X_BOUND && f->getY() > LOW_Y_BOUND && f->getY() < UP_Y_BOUND){
                        f->swim();


                        cFish.setPosition(f->getX()+500, f->getY()+500);
                        window.draw(cFish);
                        
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

            window.display();

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
}