//
// Created by cc on 15/6/20.
//

#include "Klausur.h"

Klausur::Klausur(int pVersion, int pNr, int ID, std::string pName, int pruefer1, int pruefer2, int pDauer) {

    this->pVersion=pVersion;
    this->pNR=pNr;
    this->ID=ID;
    this->pName=pName;
    this->pruefer1=pruefer1;
    this->pruefer2=pruefer2;
    this->pDauer=pDauer;
}

int Klausur::getID() {
    return this->ID;
}

int Klausur::getpVersion() {
    return this->pVersion;
}

int Klausur::getpNR() {
    return this->pNR;
}

std::string Klausur::getpName() {
    return this->pName;
}

int Klausur::getpruefer1() {
    return this->pruefer1;
}

int Klausur::getpruefer2() {
    return this->pruefer2;
}

int Klausur::getpDauer() {
    return this->pDauer;
}


