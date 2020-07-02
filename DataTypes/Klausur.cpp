//
// Created by cc on 15/6/20.
//

#include "Klausur.h"



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

int Klausur::getDauerTimeSlot() {
    return this->pDauer;
}

Klausur::Klausur(int pVersion, int pNr, int id, const std::string &pName, int pruefer1, int pruefer2, int pDauer)
        : pVersion(pVersion), pNR(pNr), ID(id), pName(pName), pruefer1(pruefer1), pruefer2(pruefer2), pDauer(pDauer) {}

void Klausur::setPDauer(int pDauer) {
    Klausur::pDauer = pDauer;
}




