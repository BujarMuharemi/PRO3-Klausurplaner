//
// Created by cc on 15/6/20.
//

#include "Student.h"

Student::Student(int mtkNr, std::string stg, int ID) {

    this->mtkNR=mtkNr;
    this->stg=stg;
    this->ID=ID;

}

int Student::getMtkNr() const {
    return mtkNR;
}

const std::string &Student::getStg() const {
    return stg;
}

int Student::getID() const {
    return ID;
}


void Student::resetReady(){
    for(int i=0;i<20;i++){
        isReady[i]= true;
    }
}

