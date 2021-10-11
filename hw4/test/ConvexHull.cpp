#include    "ConvexHull.h"

Line    ConvexHull::FindLine(const Point &p,const  Point &q){
    double p_x, p_y, q_x, q_y, a, b, c;
    Line pq;   
    p_x = p.getx();
    p_y = p.gety();
    q_x = q.getx();
    q_y = q.gety();
    a = q_y - p_y;
    b = -q_x + p_x;
    c = -a*p_x - b*p_y;
    pq.seta(a);
    pq.setb(b);
    pq.setc(c);
    return pq;
}

bool    ConvexHull::isOnRight(const Point &p,const  Point &q,const  Point &r){
    double r_x, r_y, num, a, b, c, p_x, q_x, p_y, q_y;
    Line pq;
    r_x = r.getx();
    r_y = r.gety();
    pq = FindLine(p, q);
    a = pq.geta();
    b = pq.getb();
    c = pq.getc();
    num = (a*r_x + b*r_y + c);
    if(num > 0) return true;
    else if(num == 0){
        p_x = p.getx();
        p_y = p.gety();
        q_x = q.getx();
        q_y = q.gety();
        if((p_x > r_x && r_x > q_x) || (p_x < r_x && r_x < q_x) || (p_y > r_y && r_y > q_y) || (p_y < r_y && r_y < q_y))
            return false;
        else //if((r_x > p_x && p_x > q_x) || (r_x < p_x && p_x < q_x) || (p_x > q_x && q_x > r_x) || (p_x < q_x && q_x < r_x))
            return true;
    }
    else return false;
}

Point   ConvexHull::FindLowestPoint(vector<Point> &input){
    int lowest = 0;
    for(int i = 0; i < input.size() ;i++){
        if(input.at(i).gety() < input.at(lowest).gety())
            lowest = i;
        else if(input.at(i).gety() == input.at(lowest).gety()){
            if(input.at(i).getx() < input.at(lowest).getx()){
                lowest = i;
            }
        }
    }
    return input.at(lowest);
}

double  ConvexHull::ComputeAngle(const Point &p,const  Point &q, const Point &r){
    double  a,qp, qr, qp_x, qr_x, qp_y, qr_y, angle_len;
    qp_x = p.getx() - q.getx();
    qp_y = p.gety() - q.gety();
    qr_x = r.getx() - q.getx();
    qr_y = r.gety() - q.gety();
    angle_len = (qp_x*qr_x + qp_y*qr_y) / sqrt((qp_x*qp_x + qp_y*qp_y)*(qr_x*qr_x + qr_y*qr_y) + 1e-10);
    a = acos(angle_len)*180/PI;
    return a;
}

void    ConvexHull::FindConvexHull(const vector<Point> &input, vector<Point> &output){

        //brute force
        in_convex = input;
        Line pq;
        bool right = true;
        int isright = 0;
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < input.size(); j++){
                if(i!=j){
                    for(int k = 0; k < input.size(); k++){
                        //cout << "kkk: "  << k << endl;
                        //tmp = input.at(k);
                        //cout << "tmp: " << tmp.getx() << "\t" << tmp.gety() << endl;
                        if(i!=j && j!=k && i!=k){
                            //Point tmp = input.at(k), tmp2 = input.at(i), tmp3 = input.at(j);
                            //cout << "i: " << i << "j: " << j << "k: " << k << endl;
                            //cout << "cmp: "  << tmp2.getx() << "\t" << tmp3.getx() << "\t" << tmp.getx() << endl;
                            right = isOnRight(input.at(i), input.at(j), input.at(k));
                            //cout << right << endl;
                            if(right)
                                isright = 1;
                        }
                    }
                    if(isright == 0){
                        //cout << "push: " <<i << endl;
                        output.push_back(input.at(i));  //p
                        //output.push_back(input.at(j));  //q
                        in_convex[i].setx(INF);
                        in_convex[i].sety(INF);
                    }
                    isright = 0;
                }
            }
        }

}


void  ConvexHull::FindConvexHull2(const vector<Point> & input, vector<Point> &output){
        //Jarvis' March algo.
        in_convex2 = input;
        Point   q_point, p_point, r_point, max_point, ini_point;
        double  MaxAngle = 0, angle;
        vector <Point> inp = input;
        int     hull, j =0;
        q_point = FindLowestPoint(inp);
        ini_point = q_point;
        //cout << "ini: " << ini_point.getx() << endl;
        p_point.setx(INF);
        p_point.sety(q_point.gety());
        do{
            //computangle
            MaxAngle = -1;
            for(int i = 0; i < input.size();i++){
                r_point = input.at(i);
                //cout << "r: " << r_point.getx() << "\t" << r_point.gety() << endl;
                //cout << "111_>" << "p_point: " << p_point.getx() << "q_point: " << q_point.getx() << "r_point: " << r_point.getx() << endl;
                if(!(((q_point.getx() == r_point.getx()) && (q_point.gety() == r_point.gety())) || ((p_point.getx() == r_point.getx()) && (p_point.gety() == r_point.gety())))){
                    angle = ComputeAngle(p_point, q_point, r_point);
                    //cout << "p_point: " << p_point.getx() << "q_point: " << q_point.getx() << "r_point: " << r_point.getx() << endl;
                    //cout << "angle: " << angle  << "Max_angle: " << MaxAngle<< endl;
                    if(fabs(angle -MaxAngle) < EPS){
                        Point tmp1, tmp2;
                        tmp1 = input.at(hull);
                        double len1, len2;
                        //cout<<"== " << "p_point: " << p_point.getx() << "q_point: " << q_point.getx() << "r_point: " << r_point.getx() << endl;
                        len1 = sqrt(pow((tmp1.getx()-q_point.getx()), 2) + pow((tmp1.gety() - q_point.gety()), 2));
                        len2 = sqrt(pow((r_point.getx()-q_point.getx()), 2) + pow((r_point.gety() - q_point.gety()), 2));
                        //cout << "len1: " << len1 << "len2: " << len2 << endl;
                        if(len1 < len2){
                            MaxAngle = angle;
                            max_point = r_point;
                            hull = i;
                        }
                    }
                    else if(angle > MaxAngle){
                        MaxAngle = angle;
                        max_point = r_point;
                        hull = i;
                    }
                }
            }
            //cout << max_point.getx() << "\t" << max_point.gety() << endl;
            //cout << "hull: " << hull << endl;
            r_point = max_point;
            output.push_back(r_point);
            in_convex2[hull].setx(INF);
            in_convex2[hull].sety(INF);
            p_point = q_point;
            q_point = r_point;
            //cout<<"@@ " << "p_point: " << p_point.getx() << "q_point: " << q_point.getx() << "r_point: " << r_point.getx() << endl;
            //cout << "p_point: " << p_point.getx() << "q_point: " << q_point.getx() << "r_point: " << r_point.getx() << endl;
        }while(!((r_point.getx() == ini_point.getx()) && (r_point.gety() == ini_point.gety())));
    
}