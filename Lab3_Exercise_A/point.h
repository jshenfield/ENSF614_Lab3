/*
* File Name: point.h
* Assignment: Lab 3 Exercise A
* Lab Section: B01
* Completed by: Jack Shenfield & Marley Cheema
* Submission Date: Sept 30, 2025
*/

#ifndef POINT_H
#define POINT_H

// declaration of class point

class point {

private:
    double x;
    double y;
    int id;
    static int count; // static so that all points share the same count

public:
    
    point() = delete; // delete default constructor // inspired by chatgpt
    point(double a, double b);
    // PROMISES: constructs a point object with given x and y coordinates
    void display();
    // PROMISES: displays a Point object's coordinates and id number
    double get_x() const;
    // PROMISES: returns x coordinate of point object
    double get_y() const;
    // PROMISES: returns y coordinate of point object
    int get_id() const;
    // PROMISES: returns id number of point object
    void set_x(double a);
    // PROMISES: sets x coordinate of point object
    void set_y(double b);
    // PROMISES: sets y coordinate of point object
    static int counter();
    // PROMISES: returns number of point objects created
    double distance(const point& other);
    // PROMISES: returns the distance between two points
    static double stat_distance(const point& a, const point& b);
    // PROMISES: static veresion of distance function
};

#endif