#include <iostream>
#include "Angle.h"


int main() {

    //Set up three angle objects using two different constructors
    //
    Angle a1;
    Angle a2;    
    a1.setAngle(250);
    a2.setAngle(190);
    Angle a3(40);
    //
    
    //Print out original values
    //
    std::cout << "| a1 = " << a1 << " |" << std::endl;
    std::cout << "| a2 = " << a2 << " |" << std::endl;
    std::cout << "| a3 =  " << a3 << " |" << std::endl << std::endl;
    //

    //Test each arithmetic overload
    //
    //
    //      +   +   +   +
    a3 = a1 + a2;
    std::cout << "| a1(" << a1 << ") +  a2(" << a2 << ")  =  " << a3 << std::endl;
    //
    //      -   -   -   -
    //
    a3 = a1 - a2;
    std::cout << "| a1(" << a1 << ") -  a2(" << a2 << ")  =  " << a3 << std::endl;
    //
    //      +=  +=  +=  +=
    //
    std::cout << "| a1(" << a1 << ") += a2(" << a2 << ")  =  ";
    a1+=a2;
    std::cout << a1 << std::endl;
    //
    //      -+  -+  -+  -+
    //
    std::cout << "| a1( " << a1 << ") -= a2(" << a2 << ")  = ";
    a1-=a2;
    std::cout <<  a1 << std::endl;
    //
    //      *   *   *   *
    //
    a3 = a1 * 2;
    std::cout << "| a1(" << a1 << ") *  2         = " << a3 << std::endl;
    //
    //      /   /   /   /
    //
    a3 = a1 / 3;
    std::cout << "| a1(" << a1 << ") /  3         =  " << a3 << std::endl;
    //
    //      *=  *=  *=  *=
    //
    std::cout << "| a1(" << a1 << ") *= 3         =  ";
    a1*=3;
    std::cout << a1 << std::endl;
    //
    //      /=  /=  /=  /=
    //
    std::cout << "| a1( " << a1 << ") /= 2         =  ";
    a1/=2;
    std::cout << a1 << std::endl;
    //
    //      =   =   =   =    
    //
    std::cout << "| a1( " << a1 << ") =  5000      = ";
    a1 = 5000;
    std::cout << a1 << std::endl;
    //
    //      =   =   =   =    
    //
    std::cout << "| a1(" << a1 << ") =  -321      =  "; 
    a1 = -321;
    std::cout << a1 << std::endl;
    //
    //      =   =   =   =    
    //
    std::cout << "| a1( " << a1 << ") =  a2(" << a2 << ")  = ";
    a1 = a2;
    std::cout << a1 << std::endl;
    //
    //      +=  ==  ==  ==
    //
    std::cout << "| a1(" << a1 << ") == a2(" << a2 << ")  = ";
    //
    if(a1 == a2){
        std::cout << "EQUAL" << std::endl;
    }else{
        std::cout << "NOT EQUAL" << std::endl;
    }
    //
    //      +=  ==  ==  ==
    //
    a1 = 19;
    std::cout << "| a1( " << a1 << ") == a2(" << a2 << ")  = ";
    //
    if(a1 == a2){
        std::cout << "EQUAL" << std::endl;
    }else{
        std::cout << "NOT EQUAL" << std::endl;
    }
    //
    //
    return 0;
}