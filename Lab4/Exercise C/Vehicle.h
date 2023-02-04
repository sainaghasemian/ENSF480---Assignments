// Vehicle.h

#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include "Moveable.h"
using namespace std;

class Vehicle: public Moveable
{
    public:
        Vehicle(string name);
        virtual void move();

    protected:
        string name;

};

#endif