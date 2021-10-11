#ifndef LINE_H
#define LINE_H
#include    "Point.h"

//int lowest = 0;


class Line{ // representing a line in 2D, a*x + b*y + c = 0
public:
    Line();
    Line(double ia, double ib, double ic);
    Line(const Line &p);
    bool operator==(const Line &p);
    double  geta()const;
    double  getb()const;
    double  getc()const;
    void    seta(double ia);
    void    setb(double ib);
    void    setc(double ic);
private:
    double a;
    double b;
    double c;
};

#endif