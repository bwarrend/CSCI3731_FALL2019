#include <iostream>
#include "Angle.h"


int main() {

    Angle a1;
    Angle a2;
    
    a1.setAngle(111);
    a2.setAngle(222);
    Angle a3(91);
    
    std::cout << "a1 = " << a1 << std::endl;
    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "a3 = " << a3 << std::endl;

    a3 = a1 + a2;
    std::cout << "a1(" << a1 << ") + a2(" << a2 << ") = " << a3 << std::endl;
    
    a3 = a1 - a2;
    std::cout << "a1(" << a1 << ") - a2(" << a2 << ") = " << a3 << std::endl;

    a1+=a2;
    std::cout << "a1(111) += a2(222) = " <<  a1 << std::endl;

    a1-=a2;
    std::cout << "a1(333) -= a2(222) = " <<  a1 << std::endl;

    a3 = a1 * 2;
    std::cout << "a1(" << a1 << ") * 2 = " << a3 << std::endl;

    a3 = a1 / 3;
    std::cout << "a1(" << a1 << ") / 3 = " << a3 << std::endl;

    a1*=3;
    std::cout << "a1(111) *= 3 = " << a1 << std::endl;

    a1/=2;
    std::cout << "a1(333) /= 2 = " << a1 << std::endl;

    a1 = 5000;
    std::cout << "a1(5000) = " << a1 << std::endl;

    a1 = -321;
    std::cout << "a1(-321) = " << a1 << std::endl;

    a1 = a2;
    std::cout << "a1(" << a1 << ") = a2(" << a2 << ") = " << a1 << std::endl;

    
    if(a1 == a2){
        std::cout << "EQUAL" << std::endl;
    }else{
        std::cout << "NOT EQUAL" << std::endl;
    }

    a1 = 19;

    if(a1 == a2){
        std::cout << "EQUAL" << std::endl;
    }else{
        std::cout << "NOT EQUAL" << std::endl;
    }

    return 0;
}