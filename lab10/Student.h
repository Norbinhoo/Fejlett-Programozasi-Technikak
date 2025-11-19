//
// Created by modin on 11/19/2025.
//


#ifndef LAB10_STUDENT_H
#define LAB10_STUDENT_H

#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName):id(id),firstName(firstName),lastName(lastName){}
    int getId() const{return id;}
    const string &getFirstName()const{return firstName;}
    const string &getLastName() const{return lastName;}
    void addGrade(const string& subject, double grade){
        grades[subject]=grade;
    }
    double getGrade(const string& subject) const{
        if (grades.count(subject)>0){
            return grades.at(subject);
        }
        else{
            throw out_of_range("Non existent subject!");
        }
    }           //throws out_of_range for nonexistent subject
    const map<string, double> &getGrades() const{return grades;}
    void computeAverage();
    double getAverage() const{return average;}
    friend ostream& operator<<(ostream& os, const Student& student);
};


#endif //LAB10_STUDENT_H
