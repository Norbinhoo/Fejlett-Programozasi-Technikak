//
// Created by modin on 11/12/2025.
//

#ifndef LAB9_DIRECTORY_H
#define LAB9_DIRECTORY_H


#include "FileSystemItem.h"
#include <vector>

class Directory : public FileSystemItem{
public:
    Directory(const string& name):name(name){}
    ~Directory(){
        for (auto child : children) {
            delete child;
        }
        children.clear();
    }

    void add(FileSystemItem* item){
        children.push_back(item);
    }
    void remove(const string& name);
    FileSystemItem* find(const string& name);
    long getSize() const override;
    void display(ostream& os) const override;

    friend ostream &operator+=(ostream &os,const Directory &file);
    friend ostream &operator-=(ostream &os,const Directory &file);

private:
    string name;
    vector<FileSystemItem*> children;
};


#endif //LAB9_DIRECTORY_H
