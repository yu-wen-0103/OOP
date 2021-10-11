#include    "Circle.h"

Circle::Circle(const string & color, int inp):Shape(color){
    radius = inp;
    cout << "Circle construct." << endl;
}

Circle::~Circle(){
    cout << "Circle destruct." << endl;
}

void Circle::print(){
    double area = 0;
    string color;
    area = get_area();
    color = getcolor();
    cout << color <<" circle, radius " << radius << ", area " << area << endl;   //green circle, radius 10, area 314.159
}

double Circle::get_area(){
    double area = 0;
    area = 3.14159265359 * radius* radius;
    return area;
}