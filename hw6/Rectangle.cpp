#include    "Rectangle.h"

Rectangle::Rectangle(const string &color, int inp_h, int inp_w):Shape(color){
    height = inp_h;
    width = inp_w;
    cout << "Rectangle construct." << endl;
}

Rectangle::~Rectangle(){
    cout << "Rectangle destruct." << endl;
}

void Rectangle::print(){
    double area = 0;
    string color;
    area = get_area();
    color = getcolor();
    cout << color << " rectangle, height " << height << ", width " << width << ", area " << area << endl;  //red rectangle, height 8, width 6, area 48
}

double Rectangle::get_area(){
    double area = 0;
    area = height * width;
    return area;
}