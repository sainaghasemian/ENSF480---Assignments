/*
* File Name: circle.h
* Assignment: Lab 3 Exercise A 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 11, 2022
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#include <iostream>
#include <string>

class Circle: virtual public Shape
{
    private:
        double radius;

    public:
        Circle(double radius, double x, double y, const char* shapeName);
        Circle(const Circle& source);
        Circle& operator= (const Circle& rhs);
        virtual ~Circle();

        double get_radius() const;
        void set_radius(double radius);

        double area()const;
        double perimeter()const;

        void display()const;
};

#endif