/*
* File Name: shape.cpp
* Assignment: Lab 1 Exercise B
* Lab Section: B01
* Completed by: Jack Shenfield
* Submission Date: Sept 23, 2025
*/

#include "shape.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

// implementation of class shape

shape::shape(point& a, const char* name): origin(a.get_x(), a.get_y()){
    shapeName = new char[strlen(name) + 1];
    strcpy(shapeName, name);

    return;
}

shape::~shape(){
    delete [] shapeName; // free memory
    shapeName = nullptr; // avoid pointer pointing at deallocated memory
}
 
void shape::move(double dx, double dy){
    // move origin x and y by inputted dx and dy
    origin.set_x(origin.get_x() + dx);
    origin.set_y(origin.get_y() + dy);

    return;
}

const point& shape::get_origin() const{
    return origin;
}

const char* shape::get_name() const{
    return shapeName;
}

double shape::distance(shape& other){
    return origin.distance(other.get_origin()); // use previously defined functions
}

double shape::stat_distance(const shape& a, const shape& b){
    return point::stat_distance(a.get_origin(), b.get_origin()); // use previously defined functions
}

shape::shape(const shape& other): origin(other.get_origin()){


    char* temp = new char[strlen(other.get_name()) + 1];
    strcpy(temp, other.get_name());
    shapeName = temp;

    return;
}

shape& shape::operator=(const shape& other){
    if(this != &other){ // self assignment check

        origin = other.get_origin(); // use previously defined functions to get values

        char* temp = new char[strlen(other.get_name()) + 1];
        strcpy(temp, other.get_name());
        delete [] shapeName; // free previous name memory
        shapeName = temp;
    }
    return *this;
}

void shape::display(){

    // printout lines
    cout << "Shape Name: " << shapeName << endl;
    cout << "X-coordinate: " << fixed << setprecision(2) << origin.get_x() << endl;
    cout << "Y-coordinate: " << fixed << setprecision(2) << origin.get_y() << endl;

    return;
}


