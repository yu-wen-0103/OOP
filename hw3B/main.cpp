#include	<iostream>
#include    <fstream>
#include    <math.h>
#include    <algorithm>
#include    <cstdlib>
#include    <cstring>
#include    "Polygon.h"
#include    "LinkedList.h"
using namespace std;


int     main(){
    char    buf[100] = {0}, word[10] = {0};
    int     buf_len = 0, num = 0, word_cnt = 0, point_lena = 0, point_lenb = 0, way_appear = 0, x_appear = 0, y_appear = 0, num_way = 0, num_x = 0, num_y = 0;
    Point   a_pt[1000], b_pt[1000];
    Polygon a, b;
    Polygon *copy_a,*copy_b;
    bool    re;
    ifstream    fin;
    fin.open("polydata.txt");

    //input data
    for(int i = 0; i < 2; i++){
        fin.getline(buf, sizeof(buf));
       // if(buf[strlen(buf)]== '\n')
         //   buf[strlen(buf)] = '\0';
        while(strcmp(buf, "-1") != 0){
            //init
            way_appear = 0;
            x_appear = 0;
            y_appear = 0;
            buf_len = strlen(buf);
            cout << "buf string: " << buf << "buf size: " << buf_len << endl;
            for(int j = 0; j <= buf_len; j++){
                if(isdigit(buf[j]) || buf[j] == '-' || buf[j] == ' ' || buf[j] == '\n' || buf[j] == '\0'){
                    if(isdigit(buf[j]) || buf[j] == '-'){
                        word[word_cnt] = buf[j];
                        word_cnt ++;
                    }
                    else if (buf[j] == ' ' || buf[j] == '\n' || buf[j] == '\0'){
                        if(way_appear == 0){
                            num_way = atoi(word);
                            cout << "num_way: " << num_way;
                            way_appear = 1;
                        }
                        else if(x_appear == 0 && way_appear == 1){
                            num_x = atoi(word);
                            cout << "\tnum_x: " << num_x;
                            x_appear  = 1;
                        }
                        else if(y_appear == 0 && way_appear == 1 && x_appear == 1){
                            num_y = atoi(word);
                            cout << "\tnum_y: " << num_y << endl;
                            y_appear = 1;
                        }
                        memset(word, '\0', sizeof(word));
                        word_cnt = 0;
                    }
                }
                else{
                    cout << "Input is not legal.buf: " << buf[j] << endl;
                    break;
                }
            }
            if(i == 0){
                a_pt[point_lena].way = num_way;
                a_pt[point_lena].x = num_x;
                a_pt[point_lena++].y = num_y;
            }
            else{
                b_pt[point_lenb].way = num_way;
                b_pt[point_lenb].x = num_x;
                b_pt[point_lenb++].y = num_y;
            }
            fin.getline(buf, sizeof(buf));
        }
    }
    fin.close();

    //compute
    a.setPolygon(a_pt, point_lena);
    cout << "a.setpolygon is completed." << endl;
    b.setPolygon(b_pt, point_lenb);
    cout << "b.setpolygon is completed." << endl;
    re = a.isCollide(b);
    if(re)
        cout << "-------is collide.-------" << endl;
    else
        cout << "-------not collide.-------" << endl;
    copy_a = a.splitPolygon();
   // cout << "---------------------Display a--------------------------" << endl;
    //a.displayPolygon();
    //cout << "---------------------Display copy_a--------------------------" << endl;
    //copy_a->displayPolygon();
    //copy_b = b.splitPolygon();
    //cout << "---------------------Display b--------------------------" << endl;
    //b.displayPolygon();
    //cout << "---------------------Display copy_b--------------------------" << endl;
    //copy_b->displayPolygon();
    re = copy_a->isCollide(b);
    if(re)
        cout << "-------is collide.-------" << endl;
    else
        cout << "-------not collide.-------" << endl;
        /*
    re = a.isCollide(b);
    if(re)
        cout << "-------is collide.-------" << endl;
    else
        cout << "-------not collide.-------" << endl;
    return 0;
    */
}
