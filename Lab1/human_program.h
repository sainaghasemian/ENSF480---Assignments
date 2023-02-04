/*
* File Name: human_program.h
* Assignment: Lab 1 Exercise D
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: Sept 21, 2022
*/
#include <iostream>
#include <string>

using namespace std;

#ifndef HUMAN_PROGRAM_H
#define HUMAN_PROGRAM_H

class Point
{
    private:

        double x;     // x coordinate of a location on Cartisian Plain

        double y;     // y coordinate of a location on Cartisian Plain

    public:

        Point(const double a = 0, const double b = 0);
        // PROMISES: To create a new instance of point

        double get_x()const;
        // PROMISES: Returns the value of the x coordinate

        double get_y()const; 
        // PROMISES: Returns the value of the y coordinate

        void set_x(const double a);
        // REQUIRES: The getter value of the x coordinate, get_x()
        // PROMISES: Sets the value of the set x coordinate

        void set_y(const double a);
        // REQUIRES: The getter value of the y coordinate, get_y()
        // PROMISES: Sets the value of the set y coordinate

};

class Human 
{
    private:

        Point location;   // Location of an object of Human on a Cartisian Plain

        char *name;       // Human's name

    public:
        
        Human(const char* nam = "", const double x = 0, const double y = 0);
        
        char* get_name()const;
        // PROMISES: Returns name, this is a constant function 
                
        void set_name(const char* name);
        // REQUIRES: get_name()
        // PROMISES: Sets the value of the name, this is a constant function
    
        Point get_point()const;
        // PROMISES: To return the location 
        
        virtual void display()const;
        // PROMISES: To print human location and human name 
};

#endif