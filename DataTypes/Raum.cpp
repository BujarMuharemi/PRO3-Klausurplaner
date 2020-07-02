//
// Created by cc on 15/6/20.
//

#include "Raum.h"

Raum::Raum(std::string Name, int Sitzplaetze) {
    this->Name=Name;
    this->Sitzplaetze=Sitzplaetze;

}

Raum::Raum(){}

std::string Raum::getName() {
    return this->Name;
}

int Raum::getSitzplaetze() {
    return this->Sitzplaetze;
}

void Raum::setIsReady(int index, int dauer) {

    for(int i = 0; i < dauer+2; i++){
        isReady[index+i] = false;
    }

}

bool Raum::getIsReady(int index, int dauer) {

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

void Raum::resetReady() {

    for(int i=0;i<20;i++){
        isReady[i]= true;
    }
}
