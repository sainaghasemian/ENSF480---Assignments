// Moveable.h

#ifndef MOVEABLE_H
#define MOVABLE_H
#include <iostream>
using namespace std;

class Moveable 
{  
    public:
        virtual void forward() = 0; //Since moveable is an interface, opperations will become virtual 
        virtual void backward() = 0;

};
#endif