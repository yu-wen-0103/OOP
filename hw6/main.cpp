#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include <vector>
#include <typeinfo>
int main(){
    vector<Shape*> s;
    s.push_back(new Triangle("green",8,4));
    s.push_back(new Triangle("Red",4,10));
    s.push_back(new Circle("yellow",5));
    s.push_back(new Circle("blue",10));
    s.push_back(new Rectangle("black",8,6));
    s.push_back(new Rectangle("pink",3,7));
    s.push_back(new Circle("purple",43));
    s.push_back(new Triangle("indigo",53,97));
    s.push_back(new Rectangle("orange",103,886));
    s.push_back(new Circle("white",87));
    s.push_back(new Circle("brown",69));
    cout<<endl<<"Printing all shapes..."<<endl<<endl;
    for(int i=0;i<s.size();i++){
        s[i]->print();
        cout<<endl;
    }
    cout<<endl<<"Printing only circles..."<<endl<<endl;
    for(int i=0;i<s.size();i++){
        if(typeid(*s[i])==typeid(Circle)){
            s[i]->print();
            cout<<endl;
        }
    }
    cout<<endl<<"Destructing every Objects..."<<endl<<endl;
    for(int i=0;i<s.size();i++){
        delete s[i];
    }

}


