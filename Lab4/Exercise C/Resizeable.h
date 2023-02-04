// Resizeable.h

#ifndef RESIZEABLE_H
#define RESIZEABLE_H
#include <iostream>
using namespace std;

class Resizeable
{
    public:
        virtual void enlarge(int n) = 0;
        virtual void shrink(int n) = 0;
};
#endif