
#include "Quiz.h"

int QuizItem::counter=0;
Quiz::Quiz(const string &name):id(++counter),name(name),isReady(false) {

}

void Quiz::addItem(const QuizItem &item) {
    if(isReady!=true){
        items.push_back(item);
    }
}

void Quiz::finalize() {
    isReady=true;
}
