//
// Created by modin on 10/22/2025.
//

#ifndef LAB6_QUIZ_H
#define LAB6_QUIZ_H

#include <string>
#include <vector>
#include <iostream>
#include "QuizItem.h"
using namespace std;

class Quiz {
public:
    Quiz(const string &name);
    void addItem(const QuizItem &item);
    void finalize();
    int getId() const{return id;};
    string getName() const{return name;};
    vector<QuizItem> getItems() const{return items;};
    bool getIsFinalized() const;
    void setName(const string &na){name=na;};

private:
    static int counter;
    int id;
    string name;
    vector<QuizItem> items;
    bool isReady;

};


#endif //LAB6_QUIZ_H
