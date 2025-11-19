#include <iostream>
#include "Student.h"
#include "GraduationDao.h"

using namespace std;


int main() {
    Student s1(11,"Puskas","Ferenc");
    Student s2(13,"Magyaros","Lajos");

    s1.addGrade("Matek",8.90);
    s1.addGrade("Magyar",7.50);
    s1.addGrade("Roman",4.40);
    s1.computeAverage();

    s2.addGrade("Matek",5.90);
    s2.addGrade("Magyar",7.70);
    s2.addGrade("Roman",5.80);
    s2.computeAverage();

    cout<<s1<<endl;
    cout<<s2<<endl;

    try {
        double mathGrade = s1.getGrade("Matek");
        cout << "Matek jegy: " << mathGrade << endl;

        double biologyGrade = s1.getGrade("Biologia");
        cout << "Biologia jegy: " << biologyGrade << endl;
    } catch (const out_of_range& e) {
        cerr << "Hiba: " << e.what() << endl;
    }

    const auto& gradesMap = s1.getGrades();
    cout << "All grades:\n";
    for (auto it = gradesMap.begin(); it != gradesMap.end(); ++it) {
        cout << "  " << it->first << ": " << it->second << endl;
    }


    return 0;
}