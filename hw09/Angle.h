#ifndef ANGLE_H
#define ANGLE_H

//Class Angle
//
//
class Angle {

private:

    double angle = 0.0;    

public:

    Angle();
    Angle(const double angle);

    void setAngle(const double angle);
    double getAngle() const;


    Angle operator+(const Angle& a) const;
    Angle operator-(const Angle& a) const;

    const Angle& operator+=(const Angle& a);
    const Angle& operator-=(const Angle& a);

    Angle operator*(const double num) const;
    Angle operator/(const double num) const;

    const Angle& operator*=(const double num);
    const Angle& operator/=(const double num);

    void operator=(const double num);
    void operator=(const Angle& a);

    bool operator==(const Angle& a) const;

    friend std::ostream& operator<<(std::ostream& out, const Angle& angleP);

    double getSin() const;
    double getCos() const;

    virtual ~Angle();
};



#endif