/*
* File Name: square.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Marley Cheema
* Submission Date: Sept 30, 2025
*/

#include "square.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// constructor
square::square(point& origin, const char* name, double side): shape(origin, name), side_a(side){
    // using member initializer list
}

// getter
double square::get_side_a() const {
    return side_a;
}

// setter
void square::set_side_a(double side) {
    side_a = side;
}

// area calculation
double square::area() const {
    return (side_a*side_a);
}

// perimeter calculation
double square::perimeter() const {
    return (4*side_a);
}

void square::display() const {

    // Similar printout to previous classes.
    cout << "Square Name: "  << get_name() << endl;
    cout << "X-coordinate: " << fixed << setprecision(2) << get_origin().get_x() << endl;
    cout << "Y-coordinate: " << fixed << setprecision(2) << get_origin().get_y() << endl;
    cout << "Side a: "       << fixed << setprecision(2) << side_a << endl;
    cout << "Area: "         << fixed << setprecision(2) << area() << endl;
    cout << "Perimeter: "    << fixed << setprecision(2) << perimeter() << endl;
}
