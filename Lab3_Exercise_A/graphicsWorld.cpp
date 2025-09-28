/*
* File Name: graphicsWorld.cpp
* Assignment: Lab 1 Exercise B
* Lab Section: B01
* Completed by: Jack Shenfield
* Submission Date: Sept 23, 2025
*/

// implementation of class graphicsWorld

#include "graphicsWorld.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// inspired by chatgpt - solution for name mismatches in test function and original code.
using Point = point;
using Shape = shape;
using Square = square;
using Rectangle = rectangle;

void graphicsWorld::run(){

    cout << "The author of this program is name Jack Shenfield" << endl;
    cout << "He enjoyed building this program from scratch. It was quite instructive and fun!" << endl;

#if 1 // Change 0 to 1 to test Point
    Point m (6, 8);
    Point n (6,8);
    n.set_x(9);
    cout << "\nExpected to dispaly the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.distance(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: " << Point::stat_distance(m, n);
#endif // end of block to test Point
#if 1 // Change 0 to 1 to test Square
    cout << "\n\nTesting Functions in class Square:" <<endl;
    Point Z(5,7);
    Square s(Z,  "SQUARE - S", 12);
    s.display();
#endif // end of block to test Square
#if 1 // Change 0 to 1 to test Rectangle
    cout << "\nTesting Functions in class Rectangle:";
    Point X(5,7);
    Rectangle a(X, "RECTANGLE A", 12, 15);
    a.display();
    Point Y(16,7);
    Rectangle b(Y,  "RECTANGLE B", 8, 9);
    b.display();
    double d = a.distance(b);
    cout <<"\nDistance between square a, and b is: " << d << endl;
    Rectangle rec1 = a;
    rec1.display();
    cout << "\nTesting assignment operator in class Rectangle:" <<endl;
    Point Q(3,4);
    Rectangle rec2 (Q, "RECTANGLE rec2", 11, 7);
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
#endif // end of block to test array of pointer and polymorphism

    cout << "\nEnd  testing." << endl;
    return;
}

int main() {
    graphicsWorld w;
    w.run();

    return 0;
}
