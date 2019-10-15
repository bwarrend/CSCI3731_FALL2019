#include <iostream>
#include "Angle.h"

Angle::Angle() {
}

Angle::Angle(const double angle) {
    setAngle(angle);
}

void Angle::setAngle(const double angleIn) {
    angle = angleIn;
    
    while(angle >= 360){
        angle -= 360;
    }
    
    while(angle < 0){
        angle += 360;
    }
}

double Angle::getAngle() const {
    return angle;
}

std::ostream& operator<<(std::ostream& out, const Angle& angleP){
    out << angleP.getAngle() << "\u00b0";
    return out;
}

Angle Angle::operator+(const Angle& a) const {
    return Angle(angle + a.getAngle());
}

Angle Angle::operator-(const Angle& a) const {
    return Angle(angle - a.getAngle());
}

void Angle::operator+=(const Angle& a) {
    setAngle(angle += a.getAngle());
}

void Angle::operator-=(const Angle& a) {
    setAngle(angle -= a.getAngle());
}

Angle Angle::operator*(const double num) const {
    return Angle(angle * num);
}

Angle Angle::operator/(const double num) const {
    return Angle(angle / num);
}

void Angle::operator*=(const double num) {
    setAngle(angle *= num);
}

void Angle::operator/=(const double num) {
    setAngle(angle /= num);
}

void Angle::operator=(const double num) {
    setAngle(angle = num);
}

void Angle::operator=(const Angle& a) {
    setAngle(angle = a.getAngle());
}

bool Angle::operator==(const Angle& a) const {
    if(angle == a.getAngle()) {
        return true;
    }else{
        return false;
    }
}

Angle::~Angle(){}