/*
* File Name: circle.cpp
* Assignment: Lab 3 Exercise A 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 11, 2022
*/
#include <string.h>
#include <iostream>
#include "math.h"
#include "circle.h"

using namespace std;

Circle::Circle(double radius, double x, double y, const char* shapeName): Shape(x, y, shapeName)
{
    this->radius = radius;
}

Circle::Circle(const Circle& source):Shape(source)
{
    radius = source.get_radius();
}


Circle& Circle::operator= (const Circle& rhs)
{
    Shape::operator=(rhs);
    radius = rhs.get_radius();
    return *this;
}


Circle::~Circle() {}

double Circle::get_radius() const
{
    return radius;
}

void Circle::set_radius(double radius)
{
    this-> radius = radius;
}

double Circle::area()const
{
    return 3.14159 * pow(radius,2);
}

double Circle::perimeter()const
{
    return (2 * 3.14159 * radius);
}

void Circle::display()const
{
    cout<<"Circle Name: "<<this->shapeName<<endl;
    this->origin.display();
    cout<<"Radius: "<<get_radius()<<endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimeter: "<<perimeter()<<endl;
    cout<<'\n';
    return;
}
//