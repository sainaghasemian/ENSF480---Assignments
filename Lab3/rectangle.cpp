/*
* File Name: retangle.cpp
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#include <string.h>
#include <iostream>
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char* shapeName): Shape(x, y, shapeName), Square(side_a, x, y, shapeName)
{
    this->side_b = side_b;
}

Rectangle::~Rectangle(){} //Base class destructor will be called

Rectangle::Rectangle(const Rectangle& source): Shape(source), Square(source)
{
    side_b = source.get_side_b();
}

Rectangle& Rectangle::operator= (const Rectangle& rhs)
{
    Square::operator=(rhs);
    side_b = rhs.get_side_b();
    return *this;
}

double Rectangle::area() const
{
    return side_b * get_side_a();
}

double Rectangle::perimeter() const
{
    return (side_b * 2) + (get_side_a() * 2);
}
        
double Rectangle::get_side_b() const
{
    return side_b;
}

void Rectangle::set_side_b(double side_b)
{
    this->side_b = side_b;
}

void Rectangle::display() const
{
    cout<<"Rectangle Name: "<<this->shapeName<<endl;
    this->origin.display();
    cout<<"Side a: "<<get_side_a()<<endl;
    cout<<"Side b: "<<side_b<<endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimeter: "<<perimeter()<<endl;
    cout<<'\n';
    return;
}