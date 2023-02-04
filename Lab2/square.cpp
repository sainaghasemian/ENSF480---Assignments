/*
* File Name: square.cpp
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#include <string.h>
#include <iostream>
#include "square.h"
#include "math.h"

using namespace std;

Square::Square(double side_a, double x, double y, const char* shapeName): Shape(x, y, shapeName)
{
    this->side_a = side_a;
}

Square::~Square(){} //Base class destructor will be called

Square::Square(const Square& source): Shape(source)
{
    side_a = source.get_side_a();
}

Square& Square::operator= (const Square& rhs)
{
    
    Shape::operator=(rhs);
    side_a = rhs.get_side_a();

    return *this;
}

double Square::area() const
{
    return pow(side_a, 2);
}

double Square::perimeter() const
{
    return side_a * 4;
}

double Square::get_side_a() const
{
    return side_a;
}

void Square::set_side_a(double side_a)
{
    this->side_a = side_a;
}

void Square::display() const 
{
    cout<<"Square Name: "<<this->shapeName<<endl;
    this->origin.display();
    cout<<"Side a: "<<get_side_a()<<endl;
    cout<<"Area: "<<area()<<endl;
    cout<<"Perimeter: "<<perimeter()<<endl;
    cout<<'\n';
    return;
}
