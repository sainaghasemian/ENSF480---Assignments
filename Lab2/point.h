/*
* File Name: point.h
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
using namespace std;

extern int pointCount;

class Point
{
    private:

        double x;
        double y;
        int id;
        static int index; //what is this??
        static int object_for_counter; //what is this??

    public:

        void display() const;
        Point(double x, double y);

        double get_x()const;
        double get_y()const;
        int get_id()const;

        void set_x(double x);
        void set_y(double y);
        void set_id(int id);

        double distance(const Point& point) const;

        static double distance(const Point& point1, const Point& point2);

        static int counter();


};

#endif