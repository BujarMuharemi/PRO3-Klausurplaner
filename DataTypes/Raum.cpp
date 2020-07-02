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
