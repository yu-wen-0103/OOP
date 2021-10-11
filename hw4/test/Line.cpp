//#include    "Point.h"
#include    "Line.h"


Line::Line(): a(0), b(0), c(0) {};
    
Line::Line(double ia, double ib, double ic): a(ia), b(ib), c(ic) {};

Line::Line(const Line &p): a(p.a), b(p.b), c(p.c) {};

bool Line::operator==(const Line &p) { 
    return (a == p.a) && (b == p.b) && (c == p.c); 
}

double  Line::geta()const{
    return a;
}

double  Line::getb()const{
    return  b;
}

double  Line::getc()const{
    return c;
}

void    Line::seta(double ia){
    a = ia;
}

void    Line::setb(double ib){
    b = ib;
}

void    Line::setc(double ic){
    c = ic;
}
