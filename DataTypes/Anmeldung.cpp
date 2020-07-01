//
// Created by cc on 15/6/20.
//

#include "Anmeldung.h"

Anmeldung::Anmeldung(int mtkNr, std::string stg, int ID) {

    this->mtkNR=mtkNr;
    this->stg=stg;
    this->ID=ID;

}

int Anmeldung::getMtkNr() const {
    return mtkNR;
}

const std::string &Anmeldung::getStg() const {
    return stg;
}

int Anmeldung::getID() const {
    return ID;
}


void Anmeldung::resetReady(){
    for(int i=0;i<20;i++){
        isReady[i]= true;
    }
}

