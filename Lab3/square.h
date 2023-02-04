/*
* File Name: square.h
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square: public Shape
{
    private:
        double side_a;


    public:
        Square(double side_a, double x, double y, const char* shapeName);
        
        virtual ~Square();

        Square(const Square& source);

        Square& operator= (const Square& rhs);

        virtual double area() const;
        virtual double perimeter() const;

        double get_side_a() const;
        void set_side_a(double side_a);

        virtual void display() const;
};

#endif
