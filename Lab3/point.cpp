/*
* File Name: point.cpp
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#include <string.h>
#include <iostream>
#include "point.h"
#include "math.h"
using namespace std;


int pointCount = 0;

// need to add x and y coordinates 
void Point::display() const 
{
    cout<< "X-coordinate: " << this->x << endl;
    cout<< "Y-coordinate: " << this->y << endl;
    return;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;

    pointCount++;

    this->id = 1000 + pointCount;
}

double Point::get_x()const
{
    return this->x;
}

double Point::get_y()const
{
    return this->y;
}

int Point::get_id()const
{
    return this->id;
}

void Point::set_x(double x)
{
    this->x = x;
    return;
}

void Point::set_y(double y)
{
    this->y = y;
    return;
}

void Point::set_id(int id)
{
    this->id = id;
    return;
}

double Point::distance(const Point& point) const
{
    return sqrt(pow(point.get_x() - get_x(), 2) + pow(point.get_y() - get_y(), 2));
}

double Point::distance(const Point& point1, const Point& point2) 
{
    return sqrt(pow((point2.get_x() - point1.get_x()), 2) + pow((point2.get_y()- point1.get_y()), 2));
}

int counter()
{
    return pointCount;
}
