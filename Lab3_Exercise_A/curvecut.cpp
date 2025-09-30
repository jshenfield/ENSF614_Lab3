/*
* File Name: curvecut.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Marley Cheema
* Submission Date: Sept 30, 2025
*/

#include "curvecut.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;


curvecut::curvecut(point& origin, const char* name, double radius, double side_a, double side_b): shape(origin, name), square(origin, name, side_a), circle(origin, name, radius), rectangle(origin, name, side_a, side_b){
    // using member initializer list

    if(radius > side_a || radius > side_b){
        cout << "Error: radius cannot be greater than width or length." << endl;
        exit(1);
    }

}

void curvecut::display() const{
    cout << "Curvecut Name: " << get_name() << endl;
    cout << "X-coordinate: "  << fixed << setprecision(2) << get_origin().get_x() << endl;
    cout << "Y-coordinate: "  << fixed << setprecision(2) << get_origin().get_y() << endl;
    cout << "Width: "        << fixed << setprecision(2) << get_side_a() << endl;
    cout << "Length: "        << fixed << setprecision(2) << get_side_b() << endl;
    cout << "Radius of the cut: "        << fixed << setprecision(2) << get_radius() << endl;

}

double curvecut::area() const{
    return (rectangle::area() - (circle::area()/4.0)); // rectangle area minus 1/4 of the circle's area

}

    
double curvecut::perimeter() const{
    return (rectangle::perimeter() - (2.0*get_radius()) + (0.25*circle::perimeter())); // rectangle perimeter minus 2*radius plus 1/4 circle perimeter

}
 
