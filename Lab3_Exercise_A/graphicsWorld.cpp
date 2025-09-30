/*
* File Name: graphicsWorld.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Marley Cheema
* Submission Date: Sept 30, 2025
*/

// implementation of class graphicsWorld

#include "graphicsWorld.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


void graphicsWorld::run(){
/****************************ASSUME CODE SEGMENT FOR EXERCISE A IS HERE ************************/
#if 1

double d = 0;
// Creating square and rectangle to using in shape array with my curvecut and circle
point Q(0,0);
square s (Q, "Square s", 3);

point Z(3,4);
rectangle a (Z, "Rectangle a", 5, 9);

cout << "\nTesting Functions in class Circle:" <<endl;
point X(3,5);
circle c (X,"CIRCLE C", 9);
c.display();
cout << "the area of " << c.get_name() <<" is: "<< c.area() << endl;
cout << "the perimeter of " << c.get_name() << " is: "<< c.perimeter() << endl;
d = a.distance(c);
cout << "\nThe distance between rectangle a and circle c is: " <<d;
point Y(6,5);
curvecut rc (Y, "CurveCut rc", 10, 12, 9);
rc.display();
cout << "the area of " << rc.get_name() <<" is: "<< rc.area();
cout << "the perimeter of " << rc.get_name() << " is: "<< rc.perimeter();
d = rc.distance(c);
cout << "\nThe distance between rc and c is: " <<d;

// Using array of Shape pointers:
shape* sh[4];
sh[0] = &s;
sh[1] = &a;
sh[2] = &c;
sh[3] = &rc;
sh[0]->display();
cout << "\nthe area of "<< sh[0]->get_name() << "is: "<< sh[0] ->area();
cout << "\nthe perimeter of " << sh[0]->get_name () << " is: "<< sh[0]->perimeter();
sh [1]->display();
cout << "\nthe area of "<< sh[1]->get_name() << "is: "<< sh[1] ->area();
cout << "\nthe perimeter of " << sh[1]->get_name () << " is: "<< sh[1]->perimeter();
sh [2]->display();
cout << "\nthe area of "<< sh[2]->get_name() << "is: "<< sh[2] ->area();
cout << "\nthe circumference of " << sh[2]->get_name ()<< " is: "<< sh[2]->perimeter();
sh [3]->display();
cout << "\nthe area of "<< sh[3]->get_name() << "is: "<< sh[3] ->area();
cout << "\nthe perimeter of " << sh[3]->get_name () << " is: "<< sh[3]->perimeter();
cout << "\nTesting copy constructor in class CurveCut:" <<endl;
curvecut cc = rc;
cc.display();
cout << "\nTesting assignment operator in class CurveCut:" <<endl;

point O(2,5);
curvecut cc2(O, "CurveCut cc2", 100, 12, 9);
cc2.display();
cc2 = cc;
cc2.display();
#endif
}; // END OF FUNCTION run