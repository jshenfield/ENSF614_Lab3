/*
* File Name: rectangle.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Marley Cheema
* Submission Date: Sept 30, 2025
*/

#include "rectangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

rectangle::rectangle(point& origin, const char* name, double side_a, double side_b_in): shape(origin, name), square(origin, name, side_a), side_b(side_b_in){
    // using member initializer list
}

// getter for side b
double rectangle::get_side_b() const {
    return side_b;
}

// setter for side b
void rectangle::set_side_b(double side) {
    side_b = (side < 0.0) ? 0.0 : side;
}

// area calculation
double rectangle::area() const {
    return (get_side_a()*side_b);
}

// perimeter calculation
double rectangle::perimeter() const {
    return 2.0 * (get_side_a() + side_b); // 2*side A and 2*side B
}

// similar display fucnction to square
void rectangle::display() const {
    cout << "Rectangle Name: " << get_name() << endl;
    cout << "X-coordinate: "  << fixed << setprecision(2) << get_origin().get_x() << endl;
    cout << "Y-coordinate: "  << fixed << setprecision(2) << get_origin().get_y() << endl;
    cout << "Side a: "        << fixed << setprecision(2) << get_side_a() << endl;
    cout << "Side b: "        << fixed << setprecision(2) << get_side_b() << endl;
    cout << "Area: "          << fixed << setprecision(2) << area() << endl;
    cout << "Perimeter: "     << fixed << setprecision(2) << perimeter() << endl;
}
