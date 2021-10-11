#include    "Point.h"

Point::Point(): x(0), y(0) {};

Point::Point(double ix, double iy): x(ix), y(iy) {};

Point::Point(const Point &p): x(p.x), y(p.y) {};

bool    Point::operator==(const Point &p) {
    return (x == p.x) && (y == p.y); 
}

double  Point::getx()const{
    return x;
}

double  Point::gety()const{
    return y;
}

void    Point::setx(double ix){
    x = ix;
}

void    Point::sety(double iy){
    y = iy;
}