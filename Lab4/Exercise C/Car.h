// Car.h

#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Car: public Vehicle
{
    public:
        void turn();

    private:
        int seats;
};
#endif