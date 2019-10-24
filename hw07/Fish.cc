#include <iostream>
#include <cstdlib>
#include "Fish.h"
#include "Angle.h"
#include "Population.h"


    Fish::Fish(int x, int y, int speed, int turnSpeed, int initialDirection, Population& popu)
        :turnRate(turnSpeed),
        direction(initialDirection),
        population(popu){
        this->x = x;
        this->y = y;
        this->speed = speed;
        population.addFish(this);
    }

    const int Fish::getX() const {
        return x;
    }

    const int Fish::getY() const {
        return y;
    }

    const double Fish::getDirection() const {
        return direction.getAngle();
    }

    void Fish::swim(){
        int choice = rand() % 3;
        
        if(choice == 0){
            direction -= turnRate;
        }else if(choice == 3){
            direction -= turnRate;
        }

        x += speed * direction.getCos();
        y += speed * direction.getSin();
    }

    void printFishy(Fish& fish){
        
        std::cout << "Fish   x: " << fish.getX() << "   y: " << fish.getY()
            << "   Angle: " << fish.getDirection() << std::endl;
    }







Fish::~Fish(){
    population.removeFish(this);
}