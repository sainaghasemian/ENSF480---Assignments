/*
* File Name: point.h
* Assignment: Lab 1 Exercise D
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: Sept 21, 2022
*/

#include <vector>
#include <string>

#ifndef EXC_H
#define EXC_H

using namespace std;

class Point
{
    private:

        double x;     // x coordinate of a location on Cartisian Plain

        double y;     // y coordinate of a location on Cartisian Plain

    public:

        Point(double a = 0, double b = 0);

        double get_x()const;

        double get_y()const; 

        void set_x(double a);

        void set_y(double a);
};

#endif