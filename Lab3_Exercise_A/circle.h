/*
* File Name: circle.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield, Marley Cheema
* Submission Date: Sept 30, 2025
*/

#ifndef CIRCLE_H
#define CIRCLE_H


#include "shape.h"

// declaration of class circle, derived from shape


class circle : public virtual shape {
private:
    double radius;
    static constexpr double PI = 3.1415;

public:
    circle() = delete;  // delete default constructor

    circle(point& origin, const char* name, double radius);
    // PROMISES: creates a circle object
    // REQUIRES: origin point, name is a string, radius is > 0

    double get_radius() const;
    // PROMISES: returns radius length
    void   set_radius(double side);
    // PROMISES: sets radius to new value (> 0)

    double area() const; // override
    // PROMISES: returns area of circle
    double perimeter() const; // override
    // PROMISES: returns perimeter of circle

    void display() const;
    // PROMISES: displays the name, origin, side lengths, perimeter, and area of circle object
};

#endif 
