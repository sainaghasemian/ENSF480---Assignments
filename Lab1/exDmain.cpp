/*
* File Name: exDmain.cpp
* Assignment: Lab 1 Exercise D
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: Sept 21, 2022
*/

#include <cstring>
#include <iostream>
using namespace std;

#include "human_program.h"
#include <iostream>

int main(int argc, char **argv)
{
	const double x = 2000, y = 3000;
	Human h("Ken Lai", x , y); 
    h.display();
	return 0;
}
