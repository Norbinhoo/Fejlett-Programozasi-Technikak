//
// Created by modin on 11/12/2025.
//

#include "File.h"

File::File(const string &name, long size) : FileSystemItem(name, size) {}

long File::getSize() const {
    return getBaseSize();
}

void File::display(ostream &os) const {
    os<<"Name: "<<name<<" "<<size<<"bajt";
}

FileSystemItem *File::clone() const {
    return new File(*this);
}


