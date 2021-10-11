
#include    "ConvexHull.h"

int flag = 0;
ConvexHull a, b;

ofstream    fout("Output_brutal.txt");
ofstream    fout_jav("Output_Javis.txt");

void    DrawLines(const vector<Point> &input){
    if(flag == 0){
        vector<Point> out = input;
        fout << out.size() << endl;
        for(int i = 0; i < out.size() ; i++){
            fout << out.at(i).getx() << " " << out.at(i).gety() << endl;
        }
        fout.close();
        
    }
    else{
        vector<Point> out2 = input;
        fout_jav << out2.size() << endl;
        for(int i = 0; i < out2.size() ;i++){
            fout_jav << out2.at(i).getx() << " " << out2.at(i).gety() << endl;
        }
        fout_jav.close();    
    }
}

void    DrawPoints(const vector<Point> &input){
    if(flag == 0){
        fout << b.in_convex.size()-input.size() << endl;
        for(int i = 0 ;i < b.in_convex.size();i++){
            if(b.in_convex.at(i).getx() != INF && b.in_convex.at(i).gety() != INF){
                fout << b.in_convex.at(i).getx() << " " << b.in_convex.at(i).gety() << endl;
            }
        }
        fout << endl;
    }
    else{
        fout_jav << a.in_convex2.size()-input.size() << endl;
        for(int i = 0; i<a.in_convex2.size();i++){
            if(a.in_convex2.at(i).getx() != INF && a.in_convex2.at(i).gety() != INF){
                fout_jav << a.in_convex2.at(i).getx() << " " << a.in_convex2.at(i).gety() << endl;
            }
        }
        fout_jav << endl;
    }
}


int main(){
    char    buf[1000] = {0}, word[100] = {0};
    int     point_num = 0, buf_len = 0, word_cnt = 0, x_appear = 0, y_appear = 0;
    double   x = 0, y = 0; 
    
    Point tmp;
    vector<Point> input, output, output2;
    ifstream fin;
    fin.open("Input.txt");
    double  time_use = 0;
    struct timeval start;
    struct timeval end;

    fin.getline(buf, sizeof(buf));
    point_num = atoi(buf);

    for(int i = 0; i < point_num; i++){
        fin.getline(buf, sizeof(buf));
        buf_len = strlen(buf);
        x_appear = 0;
        y_appear = 0;
        for(int j = 0 ;j <= buf_len; j++){
            if(isdigit(buf[j]) || buf[j] == '-' || buf[j] == '.' || buf[j] == ' ' || buf[j] == '\0' || buf[j] == '\n'){
                if(isdigit(buf[j]) || buf[j] == '-' ||buf[j] == '.'){
                    word[word_cnt] = buf[j];
                    word_cnt++;
                }
                else{
                    if(x_appear == 0){
                        x = atof(word);
                        //cout << "x: " << x << endl;
                        tmp.setx(x);
                        x_appear = 1;
                    }
                    else if(x_appear == 1 && y_appear == 0){
                        y = atof(word);
                        //cout << "y: " << y << endl;
                        tmp.sety(y);
                        y_appear = 1;
                    }
                    memset(word, '\0', sizeof(word));
                    word_cnt = 0;
                }
            }
            else{
                cout << "Input is not legal.\tInput: " << buf[j] << endl;
                break;
            }
        }
        input.push_back(tmp);
    }
    
    gettimeofday(&start, NULL);
    b.FindConvexHull(input, output2);
    DrawPoints(output2); // provide data to the first part of Output.txt
    DrawLines(output2); // provide data to the second part of Output.txt
    gettimeofday(&end, NULL);
    time_use = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec);
    time_use /= 1000;
    cout << "brute force: " << time_use << endl;
    
    flag = 1;
    gettimeofday(&start, NULL);
    a.FindConvexHull2(input, output);
    DrawPoints(output); // provide data to the first part of Output.txt
    DrawLines(output); // provide data to the second part of Output.txt
    gettimeofday(&end, NULL);
    time_use = (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec);
    time_use /= 1000;
    cout << "Jarvis' March algo.: " << time_use << endl;
    
    return 0;
}