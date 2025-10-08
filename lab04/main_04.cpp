#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    double coeff1[]{1,2,1};
    Polynomial p1(2,coeff1);
    double coeff2[]{2,4,0};
    Polynomial p2(2,coeff2);


    cout<<p1<<endl;
    cout<<p1.evaluate(0)<<endl;
    cout<<p1.evaluate(1)<<endl;
    cout<<p1.evaluate(2)<<endl;
    cout<<p1.derivative()<<endl;
    cout <<(-p1)<<endl;
    cout<<(p1+p2)<<endl;
    cout<<(p1-p2)<<endl;
    cout<<(p1*p2)<<endl;
    return 0;
}