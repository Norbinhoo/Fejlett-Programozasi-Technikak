#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

    Matrix m1(2, 3);
    cout<<m1<<endl;
    cout << endl;
    m1.randomMatrix(10, 50);
    cout<<m1<<endl;
    return 0;
}