/*
* File Name: human_program.cpp
* Assignment: Lab 1 Exercise D
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: Sept 21, 2022
*/

#include <cstring>
#include <iostream>
using namespace std;

#include "human_program.h"

    Point::Point(const double a, const double b): x(a), y(b){}

    double Point::get_x()const 
    {
        return x;
    } 

    double Point::get_y()const 
    {
        return y;
    }   

    void Point::set_x(const double a) 
    {
        x = a;
    }

    void Point::set_y(const double a) 
    { 
        y = a;
    }

    Human::Human(const char* nam, const double x, const double y): name(new char[strlen(nam)+1])
    {
        strcpy(this ->name, nam);
        location.set_x(x);
        location.set_y(y);
    }
    
    char* Human::get_name()const 
    {
        return name;
    } 
            
    void Human::set_name(const char* name) 
    {         
        delete[] this->name;
        free(this->name);         
        this->name = new char[strlen(name)+1];        
        strcpy(this ->name, name);
    }

    Point Human::get_point()const 
    {
        return location;
    }
    
    void Human::display()const 
    {                
        cout << "Human Name: " << name << "\nHuman Location: "
        << location.get_x() << " ,"
        << location.get_y() << ".\n" << endl;
    }
