/*
* File Name: point.cpp
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Barrett Sapunjis
* Submission Date: Oct 1, 2025
*/

// implementation of class point

#include "point.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

point::point(double a, double b){
    x = a;
    y = b;
    id = 1000 + counter();
}

void point::display(){
    // printout lines
    cout << "X-coordinate: " << fixed << setprecision(2) << x << endl;
    cout << "Y-coordinate: " << fixed << setprecision(2) << y << endl;

    return;
}

double point::get_x() const{
    return x;
}

double point::get_y() const{
    return y;
}

int point::get_id() const{
    return id;
}

void point::set_x(double a){
    x = a;
    return;
}

void point::set_y(double b){
    y = b;
    return;
}

int point::count = 0; // static member initialized at 0

int point::counter(){
    return ++count; // increment count and then return
}

double point::distance(const point& other){
    // pythagorean theorem
    double xlen = other.get_x() - x;
    double ylen = other.get_y() - y;
    return sqrt((xlen*xlen) + (ylen*ylen));

}
double point::stat_distance(const point& a, const point& b){
    // pythagorean theorem
    double xlen = b.get_x() - a.get_x();
    double ylen = b.get_y() - a.get_y();
    return sqrt((xlen*xlen) + (ylen*ylen));
    
}