#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include	<iostream>
#include    <fstream>
#include    <math.h>
#include    <algorithm>
#include    <cstdlib>
#include    <cstring>

using namespace std;

struct  Point{
    int     x;
    int     y;
    int     way; //1 is prev; 2 is next
};

struct  Node{
    Point   pt;
    Node    *next, *prev;
};

class   LinkedList{
    private:
        Node* current_pointer;
    public:
        LinkedList();
        ~LinkedList();
        int getSize() const;
        bool isEmpty();
        void clear();
        void deleteCurrentNode();
        void pointToNext();
        void pointToPrev();
        Point getCurrentPoint() const;
        void insertToNext(const Point& pt);
        void insertToPrev(const Point& pt);
        void display();
};

#endif