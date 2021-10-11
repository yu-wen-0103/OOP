#include    "Polygon.h"
#include    "LinkedList.h"
using namespace std;

Polygon::Polygon(){
    cout << "Constructing polygon…" << endl;
}

Polygon::~Polygon(){
    cout << "Deleting polygon…" << endl;
}

void    Polygon::setPolygon(Point pts[], int size){
    vertexList.clear();
    for(int i = 0; i < size; i++){
        if(pts[i].way == 1){  //prev
           // cout << "start prev insert" << endl;
            vertexList.insertToPrev(pts[i]);
            if(i != 0)
                vertexList.pointToPrev();
        }
        else if(pts[i].way == 2){  //next
           // cout << "start next insert" << endl;
            vertexList.insertToNext(pts[i]);
            if(i != 0)
                vertexList.pointToNext();
        }
    }
   // cout << "setPolygon id completed." << endl;
}

Polygon* Polygon::splitPolygon(){
    int     linked_list_size = vertexList.getSize();
    double  M_dou = floor(linked_list_size / 2) + 1;
    int     M = (int)M_dou;
    cout << "M: " << M << endl;
    Polygon* copy = new Polygon;
    for(int i = 1; i <= M; i++){
        Point tmp = vertexList.getCurrentPoint();
        copy->vertexList.insertToNext(tmp);
        copy->vertexList.pointToNext();
        vertexList.pointToNext();
    }
    copy->vertexList.pointToNext();
    for(int i = 1; i <= (linked_list_size-M); i++){
        vertexList.getCurrentPoint();
        vertexList.deleteCurrentNode();
    }
    //cout << "splitPolygon is completed." << endl;
   // cout << "copy is completed." << endl;
    return copy;
}

bool    Polygon::isCollide(Polygon& inPolygon){
    int     inpolygon_size = inPolygon.vertexList.getSize();
    bool    result;
    Point   start, end;
    for(int i = 0; i <= inpolygon_size; i++){
        start = inPolygon.vertexList.getCurrentPoint();
       // cout << "start_x: " << start.x << "\tstart_y: " << start.y << endl;
        inPolygon.vertexList.pointToNext();
        end = inPolygon.vertexList.getCurrentPoint();
       // cout << "end_x: " << end.x << "\tend_y: " << end.y << endl;
        result = isEdgeIntersect(start, end);
        if(result)
            break;
    }
   //cout << "isCollide is completed." << endl;
    return result;
}

bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x)-(q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}

bool Polygon::isEdgeIntersect(const Point& ptA, const Point& ptB){
 	Point polystart, polyend;
 	bool flag=false;
 	int count=0;
 	int size=vertexList.getSize();
 	if(size>=3){
		count=0;	
		while(count<=size){
	  		polystart=vertexList.getCurrentPoint();
           // cout << "polystart_x: " << polystart.x << "\tpolystart_y: " << polystart.y << endl;
			vertexList.pointToNext();
	  		polyend=vertexList.getCurrentPoint();
           // cout << "polyend_x: " << polyend.x << "\tpolyend_y: " << polyend.y << endl;
	       	flag=doIntersect(ptA, ptB, polystart, polyend);
	       	if(flag==true)
				break;	
			count++;
	 	}
	}
    else
	 	cout<<"This is not a polygon"<<endl;
	return flag;
}

void Polygon::displayPolygon(){
    vertexList.display();
}
