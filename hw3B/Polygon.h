#ifndef POLYGON_H
#define POLYGON_H
#include	<iostream>
#include    <fstream>
#include    <math.h>
#include    <algorithm>
#include    <cstdlib>
#include    <cstring>
#include    "LinkedList.h"

using namespace std;

class   Polygon{
    private:
        LinkedList vertexList;
    public:
        Polygon();
        ~Polygon();
        void setPolygon(Point pts[], int size);
        Polygon* splitPolygon();
        bool isCollide(Polygon& inPolygon);
        bool isEdgeIntersect(const Point& ptA, const Point& ptB);
        void displayPolygon();
};

#endif