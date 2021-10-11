#include    "Triangle.h"

Triangle::Triangle(const string & color, int inp_h, int inp_b):Shape(color){
    height = inp_h;
    base = inp_b;
    cout << "Triangle construct." << endl;
}

Triangle::~Triangle(){
    cout << "Triangle destruct." << endl;
}

void Triangle::print(){
    double area = 0;
    string color;
    area = get_area();
    color = getcolor();
    cout << color <<" triangle, height " << height << ", base " << base << ", area " << area << endl;//black triangle, height 4, base 10, area 20
}

double Triangle::get_area(){
    double area = 0;
    double h = (double)height;
    double b = (double)base;
    area  = h * b / 2;
    return area;
}