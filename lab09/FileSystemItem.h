//
// Created by modin on 11/12/2025.
//

#ifndef LAB9_FILESYSTEMITEM_H
#define LAB9_FILESYSTEMITEM_H

#include <iostream>
#include <string>

using namespace std;

class FileSystemItem {
protected:
    string name;
    long size;
public:
    FileSystemItem(const string &name,long size):name(name),size(size){}

    string getName()const{return name;}
    long getBaseSize()const{return size;}

    virtual long getSize() const = 0;
    virtual void display(ostream& os) const = 0;
    virtual FileSystemItem* clone() const = 0;

    friend ostream &operator<<(ostream &os,const FileSystemItem &file){
        file.display(os);
        return os;
    }
    bool operator<(const FileSystemItem& other) const {
        return name<other.name;
    }
};


#endif //LAB9_FILESYSTEMITEM_H
