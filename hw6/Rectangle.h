#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Circle.h"

class Rectangle : public Shape{ //derived from Shape using public inheritance
    private:
        int height;
        int width;
    public:
        Rectangle(const string &, int, int); //takes a string to initialize the rectangle's color and two ints to initialize the rectangle's height and width. The color string should be passed to the Shape constructor.
        ~Rectangle();
        void print(); // takes no argument and return nothing. The method should call the base class print() method to print the color, then print the word "rectangle" followed by the rectangle's height, width.
        double get_area(); // takes no argument and returns the rectangle's area (double type) based on its height and width.
};

#endif