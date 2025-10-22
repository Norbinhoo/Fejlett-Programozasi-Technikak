//
// Created by modin on 10/22/2025.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#ifndef LAB6_QUIZITEM_H
#define LAB6_QUIZITEM_H


class QuizItem {
public:
    int getId() const{return id;};
    string getQuestion() const{return question;};
    vector<string> getAnswers() const{return answers;};
    unsigned int getCorrectAnswer() const{return correctAnswer;};

    void setQuestion(const string &que){question=que;};
    void setAnswers(const vector<string> &ans){answers=ans;};
    void setCorrectAnswer(unsigned int in){correctAnswer=in;};

    QuizItem(const string &question, const vector<string> &answers, unsigned int correctAnswerIndex);

    bool isCorrect(unsigned int index) const;

    friend ostream &operator<<(ostream &os, const QuizItem &item);

private:
    static int counter;
    int id;
    string question;
    vector<string> answers;
    int correctAnswer;
};


#endif //LAB6_QUIZITEM_H
