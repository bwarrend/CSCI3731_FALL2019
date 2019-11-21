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

    //Changing this boolean will change the type of visualization
    auto pers = false;
    std::string title = "Fish Sim   Press x on keyboard to quit";
    //Set up a window 1000px X 1000px called Fish Sim
    sf::RenderWindow window(sf::VideoMode(1000,1000), title);
    //Create a rectangle to be the water and set location of top left to 0, 0
    sf::RectangleShape water(sf::Vector2f(1000.f,1000.f));
    water.setPosition(0, 0);
    //Make a rectangle to visualize a fish, placeholder
    sf::RectangleShape cFish(sf::Vector2f(2.f,2.f));

    //Water is black if pers is true because it flickers badly on my slow laptop if it is blue
    if(pers){
        water.setFillColor(sf::Color::Black);
    }else{
        water.setFillColor(sf::Color::Blue);
        cFish.setScale(5.f,2.f);
    }

    //At home, my PC can handle this no vsync, but on laptop, this ends up being much nicer.
    //I do like how slow this makes the visualizaiton, you can actually follow each fish. At least at 60hz.
    window.setVerticalSyncEnabled(true); 



    //Seed rng set up some constant fish related paramters
    //
    srand(time(0));
    const auto MAX_POP = 100;

    
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
    const auto SWIM_SP = 5;
    const auto TURN_SP = 30;    
    const auto INIT_DIR = 90;


    int flippyCount = 0;
    int drunkyCount = 0;


    //set us up the vector of fish pointers
    std::vector<Fish*> fishList;

    for(int i = 0; i < MAX_POP; ++i){
        FlippyFish* flippy = new FlippyFish(INIT_X, INIT_Y, SWIM_SP, TURN_SP, INIT_DIR);
        fishList.push_back(flippy);
        ++flippyCount;
        ++i;
        DrunkenFish* drunky = new DrunkenFish(INIT_X, INIT_Y, SWIM_SP+8);
        fishList.push_back(drunky);
        drunkyCount++;        
    }

    
    
    //Set up the windows main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //Draw the water Initially
        window.draw(water);

        while(flippyCount > 0 && drunkyCount > 0){
            if(!pers){
                window.draw(water);
            }
            
            //Run through the fish, kill em if they stray too far, swim if they don't, draw the fish in the window
            for(int i = 0 ; i < MAX_POP; ++i){
                if(fishList[i] != nullptr){
                    //fish pointer so we don't have to type as much
                    Fish* f;
                    f = fishList[i];            
                    if(f->getX() > LOW_X_BOUND && f->getX() < UP_X_BOUND && f->getY() > LOW_Y_BOUND && f->getY() < UP_Y_BOUND){
                        //swim
                        f->swim();

                        //Set position of the fish rectangle to the x and y of the current fish +500(center of screen)
                        cFish.setPosition(f->getX()+500, f->getY()+500);
                        
                        //Change the color of the fish to draw based on which type of fish it is
                        FlippyFish* ff = dynamic_cast<FlippyFish*>(f);
                        if(ff != nullptr){
                            cFish.setFillColor(sf::Color::Red);
                        }else{
                            cFish.setFillColor(sf::Color::Cyan);
                        }

                        //Draw the fish
                        window.draw(cFish);
                    //This is where the fish go to die   
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

            //Display the window
            window.display();

            //We could prnt a bunch of stuff to the terminal if we wanted to
            /*
            cls();
            std::cout << "**FlippyFish VS DrunkenFish**" << std::endl;
            std::cout << "Total Population: " << drunkyCount + flippyCount << std::endl;
            std::cout << "FlippyFish Remaining: " << flippyCount << std::endl;
            std::cout << "DrunkenFish Remaining: " << drunkyCount << std::endl;
            */ 


            //Close out if we press x
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                exit(0);
            } 

       
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
            exit(0);
        }
                    
        //who won?
        if(flippyCount > drunkyCount){
            window.setTitle("Flippy Fish Win!");
        }else if(drunkyCount > flippyCount){
            window.setTitle("Drunken Fish Win!");
        }else{
            window.setTitle("A draw..."); 
        }            

    }

    return 0;
}