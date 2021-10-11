#include "Mixed.h"

int main(){
    Mixed a(2, 3, 4), b(3, 4, 5);
    cout << "-a: " << -a << endl;
    a /= b;
    cout << "a /= b: " << a << endl;
    cout << "a-b: " << a-b << endl;
    a -= b ;
    
    cout << "a -= b: " << a<< endl;
    a *= b;
    cout << "a *= b: " << a  << endl;
    a = b;
    cout << "a = b: " << a << endl;
    cout << "!a: " << !a << endl;
    a += b;
    cout << "a += b: " << a << endl;

}