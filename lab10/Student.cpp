//
// Created by modin on 11/19/2025.
//

#include "Student.h"
#include <iostream>

using namespace std;

void Student::computeAverage() {
    if(grades.empty()){
        average=0.0;
        return;
    }
    double sum=0.0;
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        sum += it->second;
    }
    average=sum/grades.size();
}

ostream &operator<<(ostream &os, const Student &student) {
    os<<"ID: "<<student.id<<" Csaladnev: "<<student.firstName<<"Keresztnev: "<<student.lastName<<endl;
    os<<"Jegyek:\n";
    if(student.grades.empty()){
        os<<"Nincsenek jegyek!";
    }
    else{
        for(auto it=student.grades.begin();it!=student.grades.end();++it){
            os<<" "<<it->first <<": "<<it->second <<"\n";

        }
        os<<"Atlag: "<<student.average<<"\n";
    }


    return os;
}

