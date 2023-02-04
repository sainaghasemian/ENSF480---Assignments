/*
* File Name: graphicsWorld.cpp
* Assignment: Lab 2 Exercise B
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: October 3, 2022
*/

#include "graphicsWorld.h"
#include "point.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"

using namespace std;

void run()
{
    #if 1 // Change 0 to 1 to test Point
    Point m (6, 8);
    Point n (6,8);
    n.set_x(9);
    cout << "\nExpected to dispaly the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: "
    << Point::distance(m, n)<<endl;
    cout<< "Point Count:  " << pointCount<<endl;
    cout<<"Point count should be 2"<<endl;
    //Test get_id
    cout<<"Id of shape: "<<m.get_id()<<endl;
    #endif // end of block to test Point

    #if 1 //Test shape
    //TODO: Constructor-Rachel, getName-Rachel, both distance functions-Saina, move-Rachel
    Shape r (6, 8, "test_shape");
    Shape p (9, 8, "test_shape_2");
    cout<<"Name should be test_shape: "<<r.getName()<<endl;
    cout << "\nExpected to dispaly the distance between r and p is: 3";
    cout << "\nThe distance between r and p is: " << r.distance(p);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: "
    << Shape::distance(r, p)<<endl;
    r.move(1, 1);
    cout<<"New position should be 7, 9"<<endl;
    r.display();
    #endif

    #if 1 // Change 0 to 1 to test Square
    cout << "\n\nTesting Functions in class Square:" <<endl;
    Square s(5, 7, 12, "SQUARE - S");
    s.display();
    cout<< "POINT COUNT:  " << pointCount<<endl;

    Square c (3, 6, 8, "test_square");
    Square e (4, 9, 8, "test_square_2");
    cout << "\nExpected to dispaly the distance between r and p is: 3";
    cout << "\nThe distance between c and e is: " << c.distance(e);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: "
    << Shape::distance(c, e)<<endl;
    #endif // end of block to test Square

    #if 1 // Change 0 to 1 to test Rectangle
    cout << "\nTesting Functions in class Rectangle:";
    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    Rectangle b(16 , 7, 8, 9, "RECTANGLE B");
    b.display();
    double d = a.distance(b);
    cout <<"\nDistance between square a, and b is: " << d << endl;
    Rectangle rec1 = a;
    rec1.display();
    cout << "\nTesting assignment operator in class Rectangle:" <<endl;
    Rectangle rec2 (3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.set_side_b(200);
    a.set_side_a(100);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 12\n" << "Side b: 15\n" << "Area: 180\n" << "Perimeter: 54\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    rec2.display();
    cout << "\nTesting copy constructor in class Rectangle:" <<endl;
    Rectangle rec3 (a);
    rec3.display();
    a.set_side_b(300);
    a.set_side_a(400);
    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5\n" << "Y-coordinate: 7\n"
    << "Side a: 100\n" << "Side b: 200\n" << "Area: 20000\n" << "Perimeter: 600\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;
    rec3.display();
    cout<< "POINT COUNT:  " << pointCount<<endl;

    Rectangle t(5, 7, 12, 15, "RECTANGLE MOVE TEST");
    t.move(1, 1);
    cout<<"rectamgle move test origin should be 6, 8"<<endl;
    t.display();
    
    #endif // end of block to test Rectangle

    #if 1 // Change 0 to 1 to test using array of pointer and polymorphism
    cout << "\nTesting array of pointers and polymorphism:" <<endl;
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh [2] = &rec1;
    sh [3] = &rec3;
    sh [0]->display();
    sh [1]->display();
    sh [2]->display();
    sh [3]->display();
    cout<< "POINT COUNT:  " << pointCount<<endl;
    #endif // end of block to test array of pointer and polymorphism
}