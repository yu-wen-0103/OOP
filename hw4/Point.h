#ifndef POINT_H
#define POINT_H
#include    <iostream>
#include    <vector>
#include    <fstream>
#include    <cstdlib>
#include    <cstring>
#include    <math.h>
#include    <sys/time.h>
#define     PI 3.1415926535897931
#define     INF -999999
#define     EPS 1e-8

using namespace std;

class Point{ // representing a point in 2D, (x, y)
public:
    Point();
    Point(double ix, double iy);
    Point(const Point &p);
    bool operator==(const Point &p) ;
    double getx()const;
    double gety()const;
    void setx(double ix);
    void sety(double iy);
private:
    double x;
    double y;
};


#endif