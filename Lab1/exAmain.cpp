// exAmain.cpp
// ENSF 480 Lab 1 - Exercise A
// Author - M. Moussavi

#include <iostream>
using namespace std;
#include "mystring.h"

int main(void)
{
  Mystring *ar[3]; //No constructor called, this is a pointer
  Mystring c = 3; //Constructor with an int argument 
  ar[2] = &c;
  ar[1] = ar[0] = nullptr;
    
  // A BLOCK OF CODE BEGINS HERE
  {
    Mystring x[2]; //Default contsructor called twice

    x[0].set_str("ENEL");
    x[1].set_str("0");
    Mystring* z = new Mystring("4"); //Constructor with char* argument
      
    x[0].append(*z).append(x[1]); //Append called twice, copy constructor is called within append function since an object of class Mystring is passed to append by value

    //Destructor called twice, the two copies created from passing a mystring object into the append function must be destroyed once they are out of scope
  
    Mystring mars = x[0]; //Copy constructor called

    x[1] = x[0]; //Assignment operator called
    
    Mystring jupiter("White"); //Constructor with char* argument

      ar[0] = new Mystring ("Yellow"); //Constructor with char* argument

  } // BLOCK ENDS HERE //After block ends, X, mars, jupiter go out of scope and the destructor is called 4 times (twice for X since it has a capacity of 2)


  c.set_str("A"); 
  delete  ar [0]; //Destructor called
 
  Mystring d = "Green"; //Constructor with char* argument
  
  cout << "\nProgram terminated successfully." <<endl;
  return 0;
}

