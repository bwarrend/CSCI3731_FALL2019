#ifndef ANGLE_H
#define ANGLE_H
#include <iostream>
#include <cmath>
#include "Angle.h"

//Class Angle
//
//
template <class T> class Angle {

    private:

        T angle = 0.0;    

    public:

        //Constructor - Take angle as arg
        //
        Angle(const T angle) {
            setAngle(angle);
        }
        //

        //Set angle and ensure it is within from 0-359 inclusive
        //
        void setAngle(const T angleIn) {
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
        T getAngle() const {
            return angle;
        }
        //

        //  <<      Print out the object        <<
        //
        friend std::ostream& operator<<(std::ostream& out, const Angle& angleP){
            out << angleP.getAngle() << "\u00b0";
            return out;
        }
        //

        //  +       Add two angle objects, return a copy            +
        //
        Angle operator+(const Angle& a) const {
            return Angle(angle + a.getAngle());
        }
        //

        //  -       Subtract two angle objects, return a copy       -
        //
        Angle operator-(const Angle& a) const {
            return Angle(angle - a.getAngle());
        }
        //

        //  +=      Original angle plus-equals another angle        +=
        //
        const Angle& operator+=(const Angle& a) {
            setAngle(angle += a.getAngle());
            return *this;
        }
        //

        //  -=      Original angle subtract-equals another angle    -=
        //
        const Angle& operator-=(const Angle& a) {
            setAngle(angle -= a.getAngle());
            return *this;
        }
        //

        //  *       Multiply two angle objects, return a copy       *
        //
        Angle operator*(const T num) const {
            return Angle(angle * num);
        }
        //

        //  /       Divide two angle objects, return a copy         /
        //
        Angle operator/(const T num) const {
            return Angle(angle / num);
        }
        //

        //  *=      Original angle multiply-equals a double         +=
        //
        const Angle& operator*=(const T num) {
            setAngle(angle *= num);
            return *this;
        }
        //

        //  /=      Original angle divide-equals a double           /=
        //
        const Angle& operator/=(const T num) {
            setAngle(angle /= num);
            return *this;
        }
        //

        //  =       Sets original angle equal to double             =
        //
        void operator=(const T num) {
            setAngle(angle = num);
        }
        //

        //  =       Sets original angle equal to another angle      =
        //
        void operator=(const Angle& a) {
            setAngle(angle = a.getAngle());
        }
        //

        //  ==      Checks to see if two angles are equal, returns a bool       ==
        //
        bool operator==(const Angle& a) const {
            if(angle == a.getAngle()) {
                return true;
            }else{
                return false;
            }
        }
        //

        double getSin() const{
            return(sin(angle*M_PI/180.0));
        }

        double getCos() const{
            return(cos(angle*M_PI/180.0));
        }

        //DUSTRUCTOR!
        //
        ~Angle(){}
        //
};



#endif