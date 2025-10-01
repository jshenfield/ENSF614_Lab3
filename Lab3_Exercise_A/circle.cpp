/*
* File Name: circle.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Barrett Sapunjis
* Submission Date: Oct 1, 2025
*/

#include "circle.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

circle::circle(point& origin, const char* name, double radius_in): shape(origin, name), radius(radius_in){
    // using member initializer list
}

// getter for radius
double circle::get_radius() const {
    return radius;
}

// setter for radius
void circle::set_radius(double rad) {
    radius = (rad < 0.0) ? 0.0 : rad;
}

// area calculation
double circle::area() const {
    return (get_radius()*get_radius()*PI);
}

// perimeter calculation
double circle::perimeter() const {
    return 2.0*PI*get_radius(); // 2*PI*R
}

// similar display fucnction to square
void circle::display() const {
    cout << "Circle Name: " << get_name() << endl;
    cout << "X-coordinate: "  << fixed << setprecision(2) << get_origin().get_x() << endl;
    cout << "Y-coordinate: "  << fixed << setprecision(2) << get_origin().get_y() << endl;
    cout << "Radius: "        << fixed << setprecision(2) << get_radius() << endl;
    cout << "Area: "          << fixed << setprecision(2) << area() << endl;
    cout << "Perimeter: "     << fixed << setprecision(2) << perimeter() << endl;
}
