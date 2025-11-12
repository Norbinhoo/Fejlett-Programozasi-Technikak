//
// Created by modin on 11/12/2025.
//

#include "Directory.h"
void Directory::remove(const string &name) {
    for(auto it=children.begin();it!=children.end();it++){
        if((*it)->getName()==name){
            delete *it;
            children.erase(it);
            return;
        }
    }
}

FileSystemItem *Directory::find(const string &name) {
    for(auto child:children){
        if((child)->getName()==name){
            return child;
        }
    }
}

long Directory::getSize() const {
    int totalSize = 0;
    for (auto child : children) {
        totalSize += child->getSize();
    }
    return totalSize;
}

void Directory::display(ostream &os) const {
    os << "[DIR] " << name << " (" << getSize() << " bytes)" << endl;
    for (auto child : children) {
        child->display(os);
    }
}

ostream &operator+=(ostream &os, const Directory &file) {

}

ostream &operator-=(ostream &os, const Directory &file) {

}






