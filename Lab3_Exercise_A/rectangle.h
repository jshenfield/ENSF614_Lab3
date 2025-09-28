/*
* File Name: rectangle.h
* Assignment: Lab 1 Exercise B
* Lab Section: B01
* Completed by: Jack Shenfield
* Submission Date: Sept 23, 2025
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

// declaration of class rectangle, derived from square


class rectangle : public square {
private:
    double side_b;

public:
    rectangle() = delete;  // delete default constructor

    rectangle(point& origin, const char* name, double side_a, double side_b);
    // PROMISES: creates a rectangle object
    // REQUIRES: origin point, name is a string, two sides are doubles and > 0

    double get_side_b() const;
    // PROMISES: returns side b length
    void   set_side_b(double side);
    // PROMISES: sets sdie b length to double value > 0

    double area() const; // override
    // PROMISES: returns area of rectangle
    double perimeter() const; // override
    // PROMISES: returns perimeter of rectangle

    void display() const;
    // PROMISES: displays the name, origin, side lengths, perimeter, and area of rectangle object
};

#endif 
