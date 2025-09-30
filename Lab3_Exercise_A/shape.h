/*
* File Name: shape.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Marley Cheema
* Submission Date: Sept 30, 2025
*/

// declaration of class shape

#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"


class shape {
    
private:
    point origin;
    char* shapeName;

public:
    shape() = delete; // delete default constructor
    shape(point& a, const char* name);
    // PROMISES: constructs a new shape object at point a with a given name of type string
    virtual ~shape();
    // PROMISES: destructor for shape 

    void move(double dx, double dy);
    // PROMISES: moves the shape by x+dx and y+dy

    const point& get_origin() const;
    // PROMISES: returns the origin point of the shape
    const char* get_name() const;
    // PROMISES: returns the name of the shape
    double distance(shape& other);

    // PROMISES: returns the distances between the origins of two shapes
    static double stat_distance(const shape& a, const shape& b);
    // PROMISES: static version of distance function
    shape(const shape& other);
    
    // PROMISES: copy constructor for shape
    shape& operator=(const shape& other);
    // PROMISES: assignment operator for shape
    virtual void display() const;
    // PROMISES: displays the shape's name and origin

    virtual double area() const = 0;   // pure virtual
    virtual double perimeter() const = 0;  // pure virtual

};

#endif
