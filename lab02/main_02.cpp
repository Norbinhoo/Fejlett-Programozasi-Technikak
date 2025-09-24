#include <iostream>
#include "Point.h"
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    Point p1(1,1);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(2, 2);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    pp1->print();
    cout<<endl;


    cout<<distance(p1,p2)<<endl;

    Point p3(1,1);
    Point p4(2,2);

    if(isSquare(p1,p2,p3,p4)==true){
        cout<<"Negyzetet alkothat!";
    }
    else{
        cout<<"Nem alkothat negyzetet!";
    }

    testIsSquare("data/input.txt");

    delete pp1;
    delete pp2;


    return 0;
}
