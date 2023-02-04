/*
* File Name: rectangle.h
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/ 

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

class Rectangle: public Square
{
   private:
        double side_b;


    public:
        Rectangle(double side_b, double side_a, double x, double y, const char* shapeName);

        virtual ~Rectangle();

        Rectangle(const Rectangle& source);
        
        Rectangle& operator= (const Rectangle& rhs);

        double area() const;
        double perimeter() const;

        double get_side_b() const;
        void set_side_b(double side_b);

        void display() const;
};

#endif
