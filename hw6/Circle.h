#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape{ //derived from Shape using public inheritance
    private:
        int radius;
    public:
        Circle(const string &,int); // takes a string to initialize the circle's color and an int to initialize the circle's radius. The color string should be passed to the Shape constructor.
        ~Circle();
        void print(); // takes no argument and return nothing. This method should call the base print() method to print the color, then print the word "circle" followed by the circle's radius and area.
        double get_area(); // takes no arguments and return the circle's area (double type) based on its radius.
};

#endif