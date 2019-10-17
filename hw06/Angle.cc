#include <iostream>
#include "Angle.h"

//Constructor - No args
//
Angle::Angle() {
}
//

//Constructor - Take angle as arg
//
Angle::Angle(const double angle) {
    setAngle(angle);
}
//

//Set angle and ensure it is within from 0-359 inclusive
//
void Angle::setAngle(const double angleIn) {
    angle = angleIn;
    
    while(angle >= 360){
        angle -= 360;
    }
    
    while(angle < 0){
        angle += 360;
    }
}
//

//Return the angle
//
double Angle::getAngle() const {
    return angle;
}
//

//  <<      Print out the object        <<
//
std::ostream& operator<<(std::ostream& out, const Angle& angleP){
    out << angleP.getAngle() << "\u00b0";
    return out;
}
//

//  +       Add two angle objects, return a copy            +
//
Angle Angle::operator+(const Angle& a) const {
    return Angle(angle + a.getAngle());
}
//

//  -       Subtract two angle objects, return a copy       -
//
Angle Angle::operator-(const Angle& a) const {
    return Angle(angle - a.getAngle());
}
//

//  +=      Original angle plus-equals another angle        +=
//
void Angle::operator+=(const Angle& a) {
    setAngle(angle += a.getAngle());
}
//

//  -=      Original angle subtract-equals another angle    -=
//
void Angle::operator-=(const Angle& a) {
    setAngle(angle -= a.getAngle());
}
//

//  *       Multiply two angle objects, return a copy       *
//
Angle Angle::operator*(const double num) const {
    return Angle(angle * num);
}
//

//  /       Divide two angle objects, return a copy         /
//
Angle Angle::operator/(const double num) const {
    return Angle(angle / num);
}
//

//  *=      Original angle multiply-equals a double         +=
//
void Angle::operator*=(const double num) {
    setAngle(angle *= num);
}
//

//  /=      Original angle divide-equals a double           /=
//
void Angle::operator/=(const double num) {
    setAngle(angle /= num);
}
//

//  =       Sets original angle equal to double             =
//
void Angle::operator=(const double num) {
    setAngle(angle = num);
}
//

//  =       Sets original angle equal to another angle      =
//
void Angle::operator=(const Angle& a) {
    setAngle(angle = a.getAngle());
}
//

//  ==      Checks to see if two angles are equal, returns a bool       ==
//
bool Angle::operator==(const Angle& a) const {
    if(angle == a.getAngle()) {
        return true;
    }else{
        return false;
    }
}
//

//DUSTRUCTOR!
//
Angle::~Angle(){}
//