/*
* File Name: shape.h
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"
#include <iostream>
#include <string>
using namespace std;

class Shape
{
    protected:
        Point origin;
        char* shapeName;

    public:
        Shape(double x, double y, const char* shapeName);

        Shape& operator= (const Shape& rhs);

        Shape(const Shape& source);

        virtual ~Shape();

        const Point& getOrigin() const; 

        char* getName() const;

        virtual void display() const;

        double distance (Shape& shape);

        static double distance (Shape& shape1, Shape& shape2);

        void move (double dx, double dy);
        
};

#endif


