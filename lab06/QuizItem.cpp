//
// Created by modin on 10/22/2025.
//

#include "QuizItem.h"

int QuizItem::counter=0;
QuizItem::QuizItem(const string &question, const vector<string> &answers, unsigned int correctAnswerIndex) : id(++counter), question(question), answers(answers), correctAnswer(correctAnswerIndex) {

}

bool QuizItem::isCorrect(unsigned int index) const {
    if (index >= answers.size()) throw out_of_range("Index kivul esik a valaszok tartomanyan.");
    return index == correctAnswer;
}

ostream &operator<<(ostream &os, const QuizItem &item) {
    os << "ID: " << item.id << "\n";
    os << "Question: " << item.question << "\n";
    for (auto i = 0; i < item.answers.size(); ++i) {
        os << " [" << i << "] " << item.answers[i];
        if (i == item.correctAnswer) os << " <-- helyes";
        os << "\n";
    }
    return os;
}
