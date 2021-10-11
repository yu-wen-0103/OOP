#ifndef CONVEXHULL_H
#define CONVEXHULL_H
#include    "Line.h"



class ConvexHull{ // a class for finding convex hull of a set of points. Input is a const pass by reference vector<Point>, output is a pass by reference vector<Point>
public:
    vector <Point> in_convex, in_convex2;
    void FindConvexHull(const vector<Point> & input, vector<Point> &output);
    void FindConvexHull2(const vector<Point> & input, vector<Point> &output); // find the convex hull of input points
private:
    Line FindLine(const Point &p,const Point &q); // return a directed line pq from point p to q
    bool isOnRight(const Point &p, const Point &q,const Point &r); // return true if r is on the right side of the line from p to q. If pq is horizontal, return true only if r is above it.
    Point FindLowestPoint(vector<Point> &input); // find the lowest point(the point with the smallest y-coordinate)
    double ComputeAngle(const Point &p,const Point &q,const Point &r); // find the angle pqr of three points
};

#endif