//
// Created by modin on 11/19/2025.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename){
    ifstream fin(filename);
    if(!fin.is_open())
    {
        perror("Fajl!");
        exit(-1);
    }
    int iD;
    string firstname, lastname;

    while(fin >> iD >> firstname >> lastname){
        students.insert({ iD, Student(iD, firstname, lastname) });
    }

}

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {

}

void GraduationDao::computeAverage() {
    for (auto it = students.begin(); it != students.end(); ++it) {
        it->second.computeAverage();
    }
}
int GraduationDao::numEnrolled() const {
    return students.size();
}


