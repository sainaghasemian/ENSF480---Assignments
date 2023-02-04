/*
* File Name: curveCut.cpp
* Assignment: Lab 3 Exercise A 
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 11, 2022
*/
#include <string.h>
#include <iostream>
#include "curveCut.h"

using namespace std;

CurveCut::CurveCut(double side_b, double side_a, double x, double y, double radius, const char* shapeName): Shape(x, y, shapeName), Circle(radius, x, y, shapeName), Rectangle(side_b, side_a, x, y, shapeName) 
{
    if(radius > side_a || radius > side_b)
    {
        cout<<"ERROR: Radius is greater than the smallest side of the rectangle";
        exit(0); //Is this the right exit code??
    }
}

CurveCut::CurveCut(const CurveCut& source): Shape(source), Circle(source), Rectangle(source){}

CurveCut& CurveCut::operator= (const CurveCut& rhs)
{
    Rectangle::operator=(rhs);
    Circle::operator=(rhs);
    return *this;
}

CurveCut::~CurveCut(){}

double CurveCut::area()const
{
    double rectangleArea = Rectangle::area();
    double circleArea = Circle::area();
    return rectangleArea - (circleArea*0.25);
}

double CurveCut::perimeter()const
{
    double side_a = Rectangle::get_side_a();
    double side_b = Rectangle::get_side_b();
    double radius = Circle::get_radius();
    double c_perimeter = Circle::perimeter();
    return side_a + side_b + (side_a - radius) + (side_b - radius) + (c_perimeter * 0.25);
}

void CurveCut::display()const
{
    //cout<<"Circle Name: "<<this->shapeName<<endl; 
    //ISSUES^^^^^^^
    //NEEDS TO BE GET_NAME
    //this->origin.display(); WE CANT DISPLAY ORIGIN BECAUSE WE HAVE TO CHECK SOMEHWERE THAT 
    //X AND Y VALUES FOR BOTH CIRCLE AND RECTANGLE ARE THE SAME

    cout<<"CurveCut Name: " <<Rectangle::getName()<<endl;
    Rectangle::origin.display();
    cout<<"Width: "<<get_side_b()<<endl;
    cout<<"Length: "<<get_side_a()<<endl;
    cout<<"Radius of the cut: "<<get_radius()<<endl;
    cout<<'\n';
    return;
}