#include "Point.h"
#include "../lab03/Point.h"

#include <iostream>
#include <valarray>
#include <set>
#include <fstream>

using  namespace std;
Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}
void Point::print() const{
    cout<<x<<" "<<y<<endl;
}

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    set<double> tavolsag;
    tavolsag.insert(distance(a,b));
    tavolsag.insert(distance(a,c));
    tavolsag.insert(distance(a,d));
    tavolsag.insert(distance(b,c));
    tavolsag.insert(distance(b,d));
    tavolsag.insert(distance(c,d));
    if(tavolsag.size()==2){
        return true;
    }
    return false;

}
void testIsSquare(const char * filename){
    ifstream ifs(filename);
    if(!ifs){
        cout<<"File not found"<<endl;
        exit(1);
    }
    int x,y;
    Point points[100][100];
    int index=0;
    while(ifs>>x>>y){
        points[index][]=Point(x,y);
        ++index;
    }

}


