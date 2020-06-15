//
// Created by cc on 15/6/20.
//

#include "Raum.h"

Raum::Raum(std::string Name, int Sitzplaetze) {
    this->Name=Name;
    this->Sitzplaetze=Sitzplaetze;
}

std::string Raum::getName() {
    return this->Name;
}

int Raum::getSitzplaetze() {
    return this->Sitzplaetze;
}