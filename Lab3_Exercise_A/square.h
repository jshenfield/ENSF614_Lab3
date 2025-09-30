/*
* File Name: square.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Marley Cheema
* Submission Date: Sept 30, 2025
*/


#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

// declaration of class square, derived from shape

class square : public virtual shape {

private:
    double side_a;

public:
    square() = delete;  // delete default constructor 

    square(point& origin, const char* name, double side);
    // PROMISES: creates a square object
    // REQUIRES: origin point, name is a string, side is double and > 0

    double get_side_a() const;
    // PROMISES: returns side_a value

    void   set_side_a(double side);
    // PROMISES: sets side_a to inputted side value
    // REQUIRES: side is a double and greater than 0

    double area() const;
    // PROMISES: returns area of the square object
    double perimeter() const;
    // PROMISES: returns perimeter of the square object


    void display() const;
    // PROMISES: displays the name, origin, side lenght, perimeter, and area of square object
};

#endif  