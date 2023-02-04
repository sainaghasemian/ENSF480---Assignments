/*
* File Name: shape.cpp
* Assignment: Lab 2 Exercise B 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#include <string.h>
#include <iostream>
#include "shape.h"
#include "math.h"

using namespace std;

Shape::Shape(double x, double y, const char* shapeName): origin(Point(x,y))
{
    this->shapeName = new char[sizeof(shapeName)];
    strcpy(this->shapeName, shapeName);
}

Shape& Shape::operator = (const Shape& rhs)
{
    if(this != &rhs) 
    {
        if(shapeName) 
        {
            delete[] shapeName;
            this->shapeName = new char[sizeof(rhs.shapeName)];
            strcpy(this->shapeName, rhs.shapeName);
        }

        origin.set_x(rhs.getOrigin().get_x());
        origin.set_y(rhs.getOrigin().get_y());
        origin.set_id(rhs.getOrigin().get_id());
    }
    return *this;
}

Shape::Shape(const Shape& source):origin(Point(source.getOrigin().get_x(), source.getOrigin().get_y()))
{
  if (this == &source) return;

  this->shapeName = new char[sizeof(source.shapeName)];
  strcpy(this->shapeName, source.shapeName);
}

Shape::~Shape()
{
    delete[] this->shapeName;
}

const Point& Shape::getOrigin() const
{
    return this->origin;
}

char* Shape::getName() const
{
    return this->shapeName;
}

void Shape::display() const
{
    cout<<"Shape Name: "<<this->shapeName<<endl;
    this->origin.display();   
    cout<<'\n';
    return;
}

double Shape::distance (Shape& shape) 
{
    return Point::distance(this->origin, shape.getOrigin());
}

double Shape::distance (Shape& shape1, Shape& shape2)
{
    return Point::distance(shape1.getOrigin(), shape2.getOrigin());
}

void Shape::move (double dx, double dy)
{
    this->origin.set_x(this->origin.get_x() + dx);
    this->origin.set_y(this->origin.get_y() + dy);
    return;
}

