/*
* File Name: curvecut.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Barrett Sapunjis
* Submission Date: Oct 1, 2025
*/

#ifndef CURVECUT_H
#define CURVECUT_H    

#include "circle.h"
#include "rectangle.h"

// declaration of class curvecut, derived from circle and rectangle

class curvecut: public circle, public rectangle {

public:
    curvecut() = delete;  // delete default constructor
    
    curvecut(point& origin, const char* name, double radius, double side_a, double side_b);
    // PROMISES: creates a curvecut object
    // REQUIRES: origin point, name is a string, radius is > 0, two sides are doubles and > 0

    void display() const;
    // PROMISES: displays the name, origin, radius, side lengths, perimeter, and area of curvecut object

    double area() const; // override
    // PROMISES: returns area of curvecut object

    double perimeter() const; // override
    // PROMISES: returns perimeter of curvecut object   

};




#endif