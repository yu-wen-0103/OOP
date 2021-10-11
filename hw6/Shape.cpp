#include "Shape.h"

Shape::Shape(const string& inp){
    color = inp;
    cout << "Shape construct." << endl;
}

Shape::~Shape(){
    cout << "Shape destruct." << endl;
}

void Shape::print(){
    //
}

string Shape::getcolor(){
    return color;
}