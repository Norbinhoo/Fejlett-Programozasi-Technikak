//
// Created by modin on 11/12/2025.
//

#ifndef LAB9_FILE_H
#define LAB9_FILE_H


#include "FileSystemItem.h"

class File : public FileSystemItem{

public:
    File(const string &name,long size);

    long getSize() const override;
    void display(ostream& os) const override;
    FileSystemItem* clone() const override;
};


#endif //LAB9_FILE_H
