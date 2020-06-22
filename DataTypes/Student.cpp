//
// Created by cc on 15/6/20.
//

#include "Student.h"

Student::Student(int mtkNr,  std::string stg, int pVersion, int pNr,  std::string pForm,
                  std::string pFormTxt, int pSemester) : mtkNR(mtkNr), stg(stg), pVersion(pVersion), pNR(pNr),
                                                               pForm(pForm), pFormTXT(pFormTxt), pSemester(pSemester) {}

int Student::getMtkNr() const {
    return mtkNR;
}

const std::string &Student::getStg() const {
    return stg;
}

int Student::getPVersion() const {
    return pVersion;
}

int Student::getPnr() const {
    return pNR;
}

const std::string &Student::getPForm() const {
    return pForm;
}

const std::string &Student::getPFormTxt() const {
    return pFormTXT;
}

int Student::getPSemester() const {
    return pSemester;
}

void Student::resetReady(){
    for(int i=0;i<20;i++){
        isReady[i]= true;
    }
}
