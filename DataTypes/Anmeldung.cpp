//
// Created by cc on 15/6/20.
//

#include "Anmeldung.h"
/*
Anmeldung::Anmeldung(int mtkNr, std::string stg, int ID) {

    this->mtkNR=mtkNr;
    this->stg=stg;
    this->ID=ID;

}*/

int Anmeldung::getMtkNr() const {
    return mtkNR;
}

const std::string &Anmeldung::getStg() const {
    return stg;
}




void Anmeldung::resetReady(){
    for(int i=0;i<20;i++){
        isReady[i]= true;
    }
}

Anmeldung::Anmeldung(int mtkNr, const std::string &stg, int pNr, int pVersion) : mtkNR(mtkNr), stg(stg), pNR(pNr),
                                                                                 pVersion(pVersion) {}

int Anmeldung::getPnr() const {
    return pNR;
}

int Anmeldung::getPVersion() const {
    return pVersion;
}

void Anmeldung::setIsReady(int index, int dauer) {

    for(int i = 0; i < dauer+8; i++){
        isReady[index+i] = false;
    }


}

bool Anmeldung::getIsReady(int index, int dauer) {

    bool temp = true;

    for(int i = 0; i < dauer; i++){
        if(isReady[index+i] == false){
            temp = false;
        }
    }
    if(temp == false){
        return false;
    }else{
        return true;
    }
}



