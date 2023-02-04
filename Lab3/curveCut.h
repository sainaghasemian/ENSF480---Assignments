/*
* File Name: curveCut.h
* Assignment: Lab 3 Exercise A 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 11, 2022
*/
#ifndef CURVECUT_H
#define CURVECUT_H

#include "circle.h"
#include "rectangle.h"
#include <iostream>
#include <string>
//NEEDS GET_NAME 

class CurveCut: public Circle, public Rectangle
{
    public:
        using Rectangle::getName;
        using Rectangle::distance;

        CurveCut(double side_b, double side_a, double x, double y, double radius, const char* shapeName);
        CurveCut(const CurveCut& source);
        CurveCut& operator= (const CurveCut& rhs);
        ~CurveCut();

        double area()const;
        double perimeter()const;

        void display()const;
};

#endif